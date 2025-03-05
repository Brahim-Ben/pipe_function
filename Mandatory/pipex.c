/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:14:18 by bbenaali          #+#    #+#             */
/*   Updated: 2025/03/04 10:52:35 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <libc.h>

int	open_files2(char *av, int *fd)
{
	int	fd1;

	fd1 = open(av, O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd1 == -1)
		(write(1, "Error: Open function failed!\n", 29), close(fd[1]),
			close(fd[0]), exit(1));
	return (fd1);
}

int	open_files1(char *av, int *fd)
{
	int	fd2;

	fd2 = open(av, O_RDWR, 0777);
	if (fd2 == -1)
		(write(1, "Eror: infile doesn't exist!\n", 29), close(fd[1]),
			close(fd[0]), exit(1));
	return (fd2);
}

void	child2_process(int *fd, char **av, char **env, int num)
{
	char	*str;
	char	**arg;
	char	**splited_path;
	int		f;

	if (num == -1)
		(close(fd[0]), close(fd[1]), ft_putstr(av[3]), exit(1));
	f = open_files2(av[4], fd);
	splited_path = ft_split(get_path(env), ':');
	arg = ft_split(av[3], ' ');
	if (!arg || !splited_path)
		(for_close_files(f, fd, arg, splited_path), error_malloc(), exit(1));
	if (num == 2)
		str = check_the_command(splited_path, arg[0]);
	else
		str = arg[0];
	if (!str)
		(for_close_files(f, fd, arg, splited_path), error_malloc(), exit(1));
	if (dup2(fd[0], 0) == -1 || dup2(f, 1) == -1)
		(for_close_files(f, fd, arg, splited_path), error_dup(), exit(1));
	(close(fd[1]), close(fd[0]), close(f));
	for_free(splited_path);
	if (execve(str, arg, env) == -1)
		(write(1, "error execve\n", 13), for_free(arg), exit(1));
}

void	child1_process(int *fd, char **av, char **env, int num)
{
	char	*str2;
	char	**argg;
	char	**splited_path;
	int		f;

	if (num == -1)
		(close(fd[0]), close(fd[1]), ft_putstr(av[2]), exit(1));
	f = open_files1(av[1], fd);
	splited_path = ft_split(get_path(env), ':');
	argg = ft_split(av[2], ' ');
	if (!argg || !splited_path)
		(for_close_files(f, fd, argg, splited_path), error_malloc(), exit(1));
	if (num == 2)
		str2 = check_the_command(splited_path, argg[0]);
	else
		str2 = argg[0];
	if (!str2)
		(for_close_files(f, fd, argg, splited_path), error_malloc(), exit(1));
	if (dup2(f, 0) == -1 || dup2(fd[1], 1) == -1)
		(for_close_files(f, fd, argg, splited_path), error_dup(), exit(1));
	(close(fd[1]), close(f), close(fd[0]));
	for_free(splited_path);
	if (execve(str2, argg, env) == -1)
		(for_free(argg), perror("error execve"), exit(1));
}

int	main(int ac, char *av[], char **env)
{
	int	id;
	int	id2;
	int	fd[2];
	int	num[2];

	if (ac != 5)
		return (write(1, "Error: You should enter 4 parameters!\n", 38), 1);
	num[0] = check_the_command_one(env, av[2]);
	num[1] = check_the_command_one(env, av[3]);
	if (pipe(fd) == -1)
		return (write(1, "Error: Pipe function failed!\n", 29), 1);
	id = fork();
	if (id == -1)
		return (write(1, "Error: Fork function failed!\n", 29), 1);
	if (id == 0)
		child1_process(fd, av, env, num[0]);
	id2 = fork();
	if (id2 == -1)
		return (write(1, "Error: Fork function failed!\n", 29), 1);
	if (id2 == 0)
		child2_process(fd, av, env, num[1]);
	(close(fd[0]), close(fd[1]));
	if (waitpid(id, NULL, 0) == -1 || waitpid(id2, NULL, 0) == -1)
		return (write(1, "Error: waitpid function failed!\n", 29), 1);
	return (0);
}

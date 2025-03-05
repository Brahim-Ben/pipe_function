/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:02:15 by bbenaali          #+#    #+#             */
/*   Updated: 2025/03/05 11:31:52 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void ft_putstr_for_file(int fd, char *str)
{
	int i;
	
	i = 0;
	while(str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void first_two_here(char *av, char **env, int num)
{
	int id;
	int fd[2];
	
	if(pipe(fd) == -1)
		return (write(1, "Error : pipe function.\n", 24), exit(1));
	id = fork();
	if(id == -1)
		return (write(1, "Error : fork function.\n", 24), exit(1));
	if(id == 0)
	{
		close(fd[0]);
		if(dup2(fd[1], 1) == -1)
			write(1, "error dup2\n", 12), exit(1);
		close(fd[1]);
		first(fd, av, env, num);
	}
	else
	{
		if(dup2(fd[0], 0) == -1)
			write(1, "error dup2\n", 12), exit(1);
		(close(fd[0]), close(fd[1]));
	}
}

void	first_three_here(char *av, char **env, int num)
{
	char	*str2;
	char	**argg;
	char	**splited_path;

	if (num == -1)
		(ft_putstr(av), exit(1));
	splited_path = ft_split(get_path(env), ':');
	argg = ft_split(av, ' ');
	if (!argg || !splited_path)
		(for_close_files(argg, splited_path), error_malloc(), exit(1));
	if (num == 2)
		str2 = check_the_command(splited_path, argg[0]);
	else
		str2 = argg[0];
	if (!str2)
		(for_close_files(argg, splited_path), error_malloc(), exit(1));
	for_free(splited_path);
	if (execve(str2, argg, env) == -1)
		(for_free(argg), perror("error execve"), exit(1));
}


void second_main_two(int fd, char **av, char **env, int ac)
{
	int i;
	// int cc;
	int count;
	int num[OPEN_MAX];
	// int fd[2];

	// cc = ac - 1;
	count = 3;
	i = 0;
	while (count < (ac - 1))
	{
		num[i] = check_the_command_one(env, av[count]);
		(i++, count++);
	}
	// fd[0] = open_files1(av[1]);
	// fd[1] = open_files2(av[cc], fd[0]);
	i = 3;
	// if (dup2(fd[0], 0) == -1)
	// 	(write(1, "Error : dup2 function.\n", 23), exit(1));
	if (dup2(fd, 1) == -1)
		(write(1, "Error : dup2 function.\n", 23), exit(1));
	// (close(fd[0]), close(fd[1]));
    close (fd);
	count = 0;
	while ((ac - 3) > i)
		(first_two_here(av[i], env, num[count]), count++, i++);
	first_three_here(av[i], env, num[count]);
}

void here_doc(char **av, int ac, char **env)
{
	int fd;
	int i;
	char *str;

	i = 0;
	str = "";
	fd = open (av[5], O_CREAT | O_RDWR, 0777);
	if(fd == -1)
		write(1, "Error : open function.\n", 23), exit(1);
	// fd[1] = open ("here_doc", O_CREAT | O_RDWR, 0777);
	// if(fd[0] == -1)
	// 	write(1, "Error : open function.\n", 23), exit(1);
	
	while (ft_strncmp(av[2], str, 3) != 0)
	{
		write(1, "pipe heredoc>", 13);
		// ft_putstr_for_file(fd, str);
		str = get_next_line(0);
		if(!str)
			write(1, "error get_next_line\n", 20), exit(1);
	}
	second_main_two(fd, av, env, ac);
	// char *ar[] = {"rm", "here_doc", NULL};
	// printf("brahim is the best\n");
	// if(execve("/bin/rm", ar, NULL) == -1)
	// 	write(1, "error execve\n", 14), exit(1);
}

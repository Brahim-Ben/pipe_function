/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:02:15 by bbenaali          #+#    #+#             */
/*   Updated: 2025/03/06 21:54:21 by bbenaali         ###   ########.fr       */
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
	write(fd, "\n", 1);
}

void	first_here(int *fd, char *av, char **env, int num)
{
	char	*str2;
	char	**argg;
	char	**splited_path;

	if (num == -1)
		(close(fd[0]), close(fd[1]), exit(1));
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

void first_two_here(char *av, char **env, int num)
{
	int id;
	int fd[2];

	if(pipe(fd) == -1)
		return (write(2, "Error : pipe function.\n", 24), exit(1));
	id = fork();
	if(id == -1)
		return (write(2, "Error : fork function.\n", 24), exit(1));
	if(id == 0)
	{
		close(fd[0]);
		if(dup2(fd[1], 1) == -1)
			write(2, "error dup2\n", 12), exit(1);
		close(fd[1]);
		first_here(fd, av, env, num);
	}
	else
	{
		close (fd[1]);
		if(dup2(fd[0], 0) == -1)
			write(2, "error dup2\n", 12), exit(1);
		close(fd[0]);
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


void second_main_two(int *fd, char **av, char **env, int ac)
{
	int i;
	int cc;
	int count;
	int num[OPEN_MAX];

	cc = ac - 1;
	count = 3;
	i = 0;
	while (count < (ac - 1))
	{
		num[i] = check_the_command_one(env, av[count]);
		(i++, count++);
	}
	i = 3;
	if (dup2(fd[0], 0) == -1)
		(write(2, "Error : dup2 function.\n", 23), exit(1));
	if (dup2(fd[1], 1) == -1)
		(write(2, "Error : dup2 function.\n", 23), exit(1));
	(close(fd[0]), close(fd[1]));
	count = 0;
	while ((ac - 2) > i)
		(first_two_here(av[i], env, num[count]), count++, i++);
	int id = fork();
	// while(wait(NULL) > 0);
	if(id == 0)
		first_three_here(av[i], env, num[count]);
}

int ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while(*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}	
	return (*s1 - *s2);
}

// void here_doc(char **av, int ac, char **env)
// {
// 	int fd[2];
// 	int i;
// 	char *str;

// 	i = 0;
// 	str = "";
// 	fd[0] = open ("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0777);
// 	if(fd[0] == -1)
// 		write(2, "Error : open function.\n", 23), exit(1);
// 	write(1, "pipe heredoc> ", 14);
// 	str = get_next_line(0);
// 	if(!str)
// 		write(1, "error get_next_line\n", 20), exit(1);
// 	if(str[ft_strlen(str) - 1] == '\n')
// 		str[ft_strlen(str) - 1] = '\0';
// 	while (ft_strcmp(av[2], str) != 0)
// 	{
// 		ft_putstr_for_file(fd[0], str);
// 		write(1, "pipe heredoc> ", 14);
// 		str = get_next_line(0);
// 		if(!str)
// 			write(1, "error get_next_line\n", 20), exit(1);
// 		if(str[ft_strlen(str) - 1] == '\n')
// 			str[ft_strlen(str) - 1] = '\0';
// 	}
// 	close (fd[0]);
// 	fd[0] = open ("here_doc", O_RDONLY, 0777);
// 	if(fd[0] == -1)
// 		write(1, "Error : open function.\n", 23), exit(1);
// 	fd[1] = open (av[5], O_CREAT | O_RDWR | O_APPEND, 0777);
// 	if(fd[1] == -1)
// 		write(1, "Error : open function.\n", 23), exit(1);
// 	second_main_two(fd, av, env, ac);
// 	unlink("here_doc");
// }





void	open_here_doc(int *fd)
{
	fd[0] = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd[0] == -1)
	{
		write(2, "Error : open function.\n", 23);
		exit(1);
	}
}

void	write_to_here_doc(char *limiter, int fd)
{
	char *str;

	write(2, "pipe heredoc> ", 14);
	str = get_next_line(0);
	if (!str)
	{
		close(fd);
		return ;
	}
	if (str[ft_strlen(str) - 1] == '\n')
		str[ft_strlen(str) - 1] = '\0';
	while (ft_strcmp(limiter, str) != 0)
	{
		ft_putstr_for_file(fd, str);
		free(str);
		write(1, "pipe heredoc> ", 14);
		str = get_next_line(0);
		if (!str)
			break;
		if (str[ft_strlen(str) - 1] == '\n')
			str[ft_strlen(str) - 1] = '\0';
	}
	close(fd);
}

void	open_output_file(int *fd, char *filename)
{
	fd[1] = open(filename, O_CREAT | O_RDWR | O_APPEND, 0777);
	if (fd[1] == -1)
	{
		write(2, "Error : open function.\n", 23);
		exit(1);
	}
}

void	here_doc(char **av, int ac, char **env)
{
	int	fd[2];

	open_here_doc(fd);
	write_to_here_doc(av[2], fd[0]);
	fd[0] = open("here_doc", O_RDONLY, 0777);
	if (fd[0] == -1)
	{
		write(2, "Error : open function.\n", 23);
		exit(1);
	}
	open_output_file(fd, av[5]);
	second_main_two(fd, av, env, ac);
	unlink("here_doc");
}




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:37:24 by bbenaali          #+#    #+#             */
/*   Updated: 2025/03/05 11:04:23 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_putstr2(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	error_malloc(void)
{
	write(1, "error malloc!\n", 16);
}

void	error_dup(void)
{
	write(1, "error dup2\n", 11);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	write (1, "zsh: command not found: ", 25);
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}


void for_free(char **split)
{
	int i;

	i = 0;
	while(split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}


void	for_close_files(char **argg, char **splited_path)
{
	for_free(argg);
	for_free(splited_path);
}


int	open_files2(char *av, int fd)
{
	int	fd1;

	fd1 = open(av, O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd1 == -1)
		(write(1, "Error: Open function failed!\n", 29), close(fd), exit(1));
	return (fd1);
}

int	open_files1(char *av)
{
	int	fd2;

	fd2 = open(av, O_RDWR, 0777);
	if (fd2 == -1)
		(write(1, "Eror: infile doesn't exist!\n", 29), exit(1));
	return (fd2);
}



int ft_strncmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while(*s1 == *s2 && *s1 && n > i)
	{
		s1++;
		s2++;
		n--;
	}
	if(n == i)
		return (0);
	return (*s1 - *s2);
}

char *get_path(char **env)
{
	int i;

	i = 0;
	while(env[i])
	{
		if(ft_strncmp(env[i], "PATH=", 5) == 0)
			return (&env[i][5]);
		i++;
	}
	return (NULL);
}

// void first(int *fd, char **av, char **env)
// {
	// char *path;
	
	// (void)fd;
	// path = get_phat(env);
	

char	*check_the_command(char **splited_path, char *av)
{
	char	*str;
	int		i;
	char	*tmp;

	i = 0;
	if (av[0] == '/' || av[0] == '.')
		(write(1, "zsh: no such file or directory: ", 33),
			ft_putstr2(av), exit(1));
	while (splited_path[i] != NULL)
	{
		str = ft_strjoin(splited_path[i], "/");
		if (!str)
			return (NULL);
		tmp = str;
		str = ft_strjoin(str, av);
		if (!str)
			return (NULL);
		free(tmp);
		if (access(str, F_OK | X_OK) == 0)
			break ;
		i++;
		free(str);
	}
	return (str);
}

void	first(int *fd, char *av, char **env, int num)
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
void	first_three(char *av, char **env, int num)
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
// }
int ft_count_wrd(char **splited_path)
{
	int i;
	
	i = 0;
	while(splited_path[i] != NULL)
		i++;
	return (i);
}

int	check_the_command_two(char **splited_path, char **arg)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	while (splited_path[i] != NULL)
	{
		str = ft_strjoin(splited_path[i], "/");
		tmp = str;
		str = ft_strjoin(str, arg[0]);
		free(tmp);
		if (access(str, F_OK | X_OK) == 0)
		{
			free(str);
			break ;
		}
		(free(str), i++);
	}
	return (i);
}

int	check_the_command_one(char **env, char *av)
{
	char	**arg;
	int		count;
	int		i;
	char	**splited_path;
	char	*path_env;

	arg = ft_split(av, ' ');
	path_env = get_path(env);
	splited_path = ft_split(path_env, ':');
	if (access(arg[0], F_OK | X_OK) == 0)
	{
		return (for_free(arg), for_free(splited_path), 0);
	}
	count = ft_count_wrd(splited_path);
	i = check_the_command_two(splited_path, arg);
	for_free(splited_path);
	for_free(arg);
	if (count == i)
		return (-1);
	return (2);
}
void first_two(char *av, char **env, int num)
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

void second_main(int *fd, char **av, char **env, int ac)
{
	int i;
	int cc;
	int count;
	int num[OPEN_MAX];
	// int fd[2];

	cc = ac - 1;
	count = 2;
	i = 0;
	while (count < (ac - 1))
	{
		num[i] = check_the_command_one(env, av[count]);
		(i++, count++);
	}
	fd[0] = open_files1(av[1]);
	fd[1] = open_files2(av[cc], fd[0]);
	i = 2;
	if (dup2(fd[0], 0) == -1)
		(write(1, "Error : dup2 function.\n", 23), exit(1));
	if (dup2(fd[1], 1) == -1)
		(write(1, "Error : dup2 function.\n", 23), exit(1));
	(close(fd[0]), close(fd[1]));
	count = 0;
	while ((ac - 2) > i)
		(first_two(av[i], env, num[count]), count++, i++);
	first_three(av[i], env, num[count]);
}

// void second_main_two(int *fd, char **av, char **env, int ac)
// {
// 	int i;
// 	// int cc;
// 	int count;
// 	int num[OPEN_MAX];
// 	// int fd[2];

// 	// cc = ac - 1;
// 	count = 3;
// 	i = 0;
// 	while (count < (ac - 1))
// 	{
// 		num[i] = check_the_command_one(env, av[count]);
// 		(i++, count++);
// 	}
// 	// fd[0] = open_files1(av[1]);
// 	// fd[1] = open_files2(av[cc], fd[0]);
// 	i = 3;
// 	if (dup2(fd[0], 0) == -1)
// 		(write(1, "Error : dup2 function.\n", 23), exit(1));
// 	if (dup2(fd[1], 1) == -1)
// 		(write(1, "Error : dup2 function.\n", 23), exit(1));
// 	(close(fd[0]), close(fd[1]));
// 	count = 0;
// 	while ((ac - 3) > i)
// 		(first_two(av[i], env, num[count]), count++, i++);
// 	first_three(av[i], env, num[count]);
// }

// void ft_putstr_for_file(int fd, char *str)
// {
// 	int i;
	
// 	i = 0;
// 	while(str[i] != '\0')
// 	{
// 		write(fd, &str[i], 1);
// 		i++;
// 	}
// }

// void here_doc(char **av, int ac, char **env)
// {
// 	int fd[2];
// 	int i;
// 	char *str;
// 	(void)ac;
// 	(void)env;

// 	i = 0;
// 	str = "";
// 	fd[0] = open (av[5], O_CREAT | O_RDWR, 0777);
// 	if(fd[1] == -1)
// 		write(1, "Error : open function.\n", 23), exit(1);
// 	fd[1] = open ("here_doc", O_CREAT | O_RDWR, 0777);
// 	if(fd[0] == -1)
// 		write(1, "Error : open function.\n", 23), exit(1);
	
// 	while (ft_strncmp(av[2], str, 3) != 0)
// 	{
// 		write(1, "pipe heredoc>", 13);
// 		ft_putstr_for_file(fd[0], str);
// 		str = get_next_line(0);
// 		if(!str)
// 			write(1, "error get_next_line\n", 20), exit(1);
// 	}
// 	second_main_two(fd, av, env, ac);
// 	// char *ar[] = {"rm", "here_doc", NULL};
// 	// printf("brahim is the best\n");
// 	// if(execve("/bin/rm", ar, NULL) == -1)
// 	// 	write(1, "error execve\n", 14), exit(1);
// }

int main(int ac, char *av[], char **env)
{
	int fd[2];

	if (ac < 5)
	   return (write(1, "please enter more than how you enter of argement :)\n", 52), 1);
	else if(ft_strncmp("here_doc", av[1], 8) == 0)
	{
		if(ac != 6)
			return(write(1, "if you want to use here_doc enter 6 argement please :)\n", 55), 1);
		else 
		{
			here_doc(av, ac, env);
		}
	}
	else
		second_main(fd, av, env, ac);
}

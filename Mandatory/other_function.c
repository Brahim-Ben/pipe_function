/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:04:30 by bbenaali          #+#    #+#             */
/*   Updated: 2025/03/02 11:51:41 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

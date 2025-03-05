/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:37:05 by bbenaali          #+#    #+#             */
/*   Updated: 2025/03/04 21:51:58 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
#include "../Mandatory/pipex.h"
// # include <sys/wait.h>
# include <stdlib.h>
// # include <limits.h>
// # include <fcntl.h>
/*******************/
// #include <stdio.h>
/*******************/

char	**ft_split(char const *s, char c);
void	ft_putstr(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	for_free(char **split);
char	*get_path(char **env);
void	ft_putstr2(char *s);
char	*check_the_command(char **splited_path, char *av);
int		check_the_command_two(char **splited_path, char **arg);
int		check_the_command_one(char **env, char *av);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	for_close_files(int fd2, int *fd, char **argg, char **splited_path);
void	error_dup(void);
void	error_malloc(void);
int		ft_count_wrd(char **s);

#endif
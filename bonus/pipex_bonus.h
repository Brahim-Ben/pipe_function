/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:06:46 by bbenaali          #+#    #+#             */
/*   Updated: 2025/03/05 11:09:02 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <libc.h>
#include "../Mandatory/pipex.h"
#include "get_next_line.h"


/*************/
#include <stdio.h>

char	**ft_split(char const *s, char sep);
char	*ft_strjoin(char *s1, char *s2);
void here_doc(char **av, int ac, char **env);
int ft_strncmp(char *s1, char *s2, int n);
int	check_the_command_one(char **env, char *av);
void	ft_putstr(char *s);
char *get_path(char **env);
void	for_close_files(char **argg, char **splited_path);
void	error_dup(void);
void	error_malloc(void);
char	*check_the_command(char **splited_path, char *av);
void	first(int *fd, char *av, char **env, int num);
void for_free(char **split);

#endif
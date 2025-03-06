/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:06:46 by bbenaali          #+#    #+#             */
/*   Updated: 2025/03/06 21:54:08 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <libc.h>
#include "get_next_line_bonus.h"
 
/************/
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
void for_free(char **split);
int ft_strcmp(char *s1, char *s2);
void	ft_putstr2(char *s);
char	*check_the_command_bonus(char **splited_path, char *av);
int		check_the_command_two_bonus(char **splited_path, char **arg);
int		check_the_command_one_bonus(char **env, char *av);
int		ft_strncmp_bonus(const char *s1, const char *s2, size_t n);
void	for_close_files_bonus(int fd2, int *fd, char **argg, char **splited_path);
int		ft_count_wrd(char **s);
int	open_files2(char *av, int fd);
int	open_files1(char *av);
int	open_files1_bonus(char *av, int *fd);
int	open_files2_bonus(char *av, int *fd);
void    pip_bonus(int ac, char *av[], char **env);



#endif
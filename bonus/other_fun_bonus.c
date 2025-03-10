/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_fun_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:32:00 by bbenaali          #+#    #+#             */
/*   Updated: 2025/03/06 21:53:14 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strncmp_bonus(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (*s1 == *s2 && *s1 && n > i)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == i)
		return (i);
	return (*s1 - *s2);
}

// int	ft_count_wrd(char **s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != NULL)
// 		i++;
// 	return (i);
// }

void	for_close_files_bonus(int fd2, int *fd, char **argg, char **splited_path)
{
	close(fd2);
	close(fd[1]);
	close(fd[0]);
	for_free(argg);
	for_free(splited_path);
}

// void	error_malloc(void)
// {
// 	write(2, "error malloc!\n", 16);
// }

// void	error_dup(void)
// {
// 	write(2, "error dup2\n", 11);
// }

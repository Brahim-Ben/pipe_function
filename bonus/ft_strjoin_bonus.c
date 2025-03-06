/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:36:00 by bbenaali          #+#    #+#             */
/*   Updated: 2025/03/05 10:20:20 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// void	ft_putstr(char *s)
// {
// 	int	i;

// 	i = 0;
// 	write (1, "zsh: command not found: ", 25);
// 	while (s[i] != '\0')
// 	{
// 		write (1, &s[i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// }

// static size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// static char	*ft_strdup(const char *s1)
// {
// 	int		i;
// 	size_t	len;
// 	char	*copy;

// 	if (!s1)
// 		return (NULL);
// 	len = ft_strlen(s1);
// 	i = 0;
// 	copy = malloc (sizeof(char) * (len + 1));
// 	if (copy == NULL)
// 		return (NULL);
// 	while (s1[i] != '\0')
// 	{
// 		copy[i] = s1[i];
// 		i++;
// 	}
// 	copy[i] = '\0';
// 	return (copy);
// }

// static void	ft_strcat(char *dest, char const *src)
// {
// 	while (*src != '\0')
// 	{
// 		*dest = *src;
// 		dest++;
// 		src++;
// 	}
// 	*dest = '\0';
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	size_t	len;
// 	size_t	i;
// 	char	*s3;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	else if (!s1)
// 		return (ft_strdup(s2));
// 	else if (!s2)
// 		return (ft_strdup(s1));
// 	len = ft_strlen(s1) + ft_strlen(s2);
// 	s3 = malloc(sizeof(char) * (len + 1));
// 	if (s3 == NULL)
// 		return (NULL);
// 	ft_strcat(s3, s1);
// 	i = ft_strlen(s3);
// 	ft_strcat(&s3[i], s2);
// 	return (s3);
// }
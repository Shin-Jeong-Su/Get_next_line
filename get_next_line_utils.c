/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:45:41 by jeshin            #+#    #+#             */
/*   Updated: 2023/10/31 22:00:25 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (!(unsigned char)c)
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ret = (char *)malloc(len_s1 + len_s2 + 1);
	if (!ret)
		return (0);
	i = 0;
	while (i < len_s1)
	{
		ret[i] = *s1;
		s1++;
		i++;
	}
	while (i - len_s1 < len_s2)
	{
		ret[i] = *s2;
		s2++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}
#include <stdio.h>
char	*get_line(char **buf)
{
	char	*front;
	char	*back;
	int		i;
	int		j;

	i = 0;
	while ((*buf)[i] && (*buf)[i] != '\n')
		i++;
	front = (char *)malloc(sizeof(char) * (i + 2));
	back = (char *)malloc(sizeof(char) * (ft_strlen(*buf) - i + 1));
	i = 0;
	while((*buf)[i] && (*buf)[i] != '\n'){
		front[i] = (*buf)[i];
		i++;
	}
	front[i++] = '\n';
	front[i] = 0;
	j = 0;
	if ((*buf)[i] && (*buf)[i] == '\n')
		i++;
	while((*buf)[i])
		back[j++] = (*buf)[i++];
	back[j] = 0;
	*buf = back;
	return (front);
}
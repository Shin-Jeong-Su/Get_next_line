/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_t_list_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:56:01 by jeshin            #+#    #+#             */
/*   Updated: 2023/11/19 18:36:15 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	len_check(char const *s, unsigned int start, size_t *len)
{
	if (start >= ft_strlen(s))
		*len = 0;
	else
	{
		if (start + *len > ft_strlen(s))
			*len = ft_strlen(s) - start;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;

	len_check(s, start, &len);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	i = 0;
	j = 0;
	while (s[i] && j < len)
	{
		if (i >= start)
			ret[j++] = s[i];
		i++;
	}
	ret[j] = 0;
	return (ret);
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

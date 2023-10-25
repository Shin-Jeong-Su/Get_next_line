/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:45:41 by jeshin            #+#    #+#             */
/*   Updated: 2023/10/25 17:05:35 by jeshin           ###   ########.fr       */
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

char	*ft_strdup_till_c(const char *s, char c)
{
	char	*ret;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (0);
	i = 0;
	while (*s && *s != c)
	{
		ret[i] = *s;
		s++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}

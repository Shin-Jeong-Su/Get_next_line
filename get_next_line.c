/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:54:39 by jeshin            #+#    #+#             */
/*   Updated: 2023/11/09 23:57:55 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_m(char **buf)
{
	char	*front;
	char	*back;
	size_t		i;

	i = 0;
	while((*buf)[i]){
		i++;	
		if((*buf)[i]=='\n')
			break;
	}
	front = ft_substr(*buf,0,i);
	back = ft_substr(*buf, i + 1, ft_strlen(*buf) - i);
	*buf = back;
	return (front);
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			rd_val;
	static char	*ret;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	buf[BUFFER_SIZE]=0;
	while(1)
	{
		rd_val = read(fd,buf,BUFFER_SIZE);
		if (rd_val < 0)
		{
			free(buf);
			free(ret);
			return (0);
		}
		else if(!rd_val)
			return (get_line_m(&ret));
		ret=ft_strjoin(ret,buf);
		if (ft_strchr(ret, '\n'))
			return (get_line_m(&ret));
	}
	return (0);
}

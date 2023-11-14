/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:54:39 by jeshin            #+#    #+#             */
/*   Updated: 2023/11/14 17:44:54 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line_m(char **bkup,int *rd_val)
{
	static char		*front;
	static char		*back;
	char			*tmp;
	size_t			i;
	size_t			bkup_size;

	bkup_size = ft_strlen(*bkup);
	if (!*rd_val)
	{
		if(**bkup)
		{
			tmp = ft_substr(*bkup,0,bkup_size);
			free(*bkup);
			*bkup = 0;
			return (tmp);
		}
		else
			return (0);
	}
	i = 0;
	while ((*bkup)[i] && (*bkup)[i] != '\n')
		i++;
	if (front)
		free(front);
	front = ft_substr(*bkup, 0, (i + 1));
	if (!back)
		back = ft_substr(*bkup, i + 1, bkup_size - (i + 1));
	else
	{
		tmp = back;
		back = ft_substr(*bkup, i + 1, bkup_size - (i + 1));
		free(tmp);
	}
	*bkup = back;
	return (front);
}

char	*get_next_line(int fd)
{
	int			rd_val;
	char		buf[BUFFER_SIZE+1];
	static char	*bkup;
	char		*tmp_bkup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (1)
	{
		rd_val = read(fd, buf, BUFFER_SIZE);
		if (rd_val < 0)
			return (0);
		buf[rd_val] = 0;
		if (!rd_val)
		{
			if (!bkup)
				return (0);
			return (get_line_m(&bkup, &rd_val));
		}
		if (!bkup)
			bkup = ft_strjoin(bkup, buf);
		else
		{
			tmp_bkup = bkup;
			bkup = ft_strjoin(bkup, buf);
			free(tmp_bkup);
		}
		if (ft_strchr(bkup, '\n'))
			return (get_line_m(&bkup,&rd_val));
	}
	return (0);
}

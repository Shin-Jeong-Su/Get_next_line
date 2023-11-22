/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:54:39 by jeshin            #+#    #+#             */
/*   Updated: 2023/11/21 15:35:01 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_till_lf(char **bkup)
{
	char		*front;
	char		*tmp_fre;
	size_t		i;

	i = 0;
	while ((*bkup)[i] && (*bkup)[i] != '\n')
		i++;
	front = ft_substr(*bkup, 0, (i + 1));
	tmp_fre = *bkup;
	if (ft_strlen(*bkup) == i + 1)
		*bkup = 0;
	else
		*bkup = ft_substr(*bkup, i + 1, ft_strlen(*bkup) - (i + 1));
	free(tmp_fre);
	return (front);
}

char	*get_line_remains(char **bkup)
{
	char		*remains;

	if (!*bkup)
		return (0);
	else if (ft_strchr(*bkup, '\n'))
		return (get_line_till_lf(bkup));
	remains = ft_substr(*bkup, 0, ft_strlen(*bkup));
	free(*bkup);
	*bkup = 0;
	return (remains);
}

char	*free_bkup(char **bkup)
{
	if (*bkup)
		free(*bkup);
	*bkup = 0;
	return (0);
}

void	new_bkup(char **bkup, char *buf)
{
	char		*tmp_fre;

	if (!*bkup)
		*bkup = ft_strjoin(*bkup, buf);
	else
	{
		tmp_fre = *bkup;
		*bkup = ft_strjoin(*bkup, buf);
		free(tmp_fre);
	}
}

char	*get_next_line(int fd)
{
	int			rd_val;
	char		buf[BUFFER_SIZE + 1];
	static char	*bkup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (1)
	{
		rd_val = read(fd, buf, BUFFER_SIZE);
		if (rd_val < 0)
			return (free_bkup(&bkup));
		buf[rd_val] = 0;
		if (!rd_val)
			return (get_line_remains(&bkup));
		new_bkup(&bkup, buf);
		if (ft_strchr(bkup, '\n'))
			return (get_line_till_lf(&bkup));
	}
	return (0);
}

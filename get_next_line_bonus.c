/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:57:46 by jeshin            #+#    #+#             */
/*   Updated: 2023/11/22 18:07:16 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*make_chunk(int fd)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	ret->fd = fd;
	ret->bkup = 0;
	ret->next = 0;
	return(ret);
}

t_list		*get_chunk(t_list **lst, int fd)
{
	t_list	*ret;
	t_list	*new;

	if (!*lst)
	{
		*lst = make_chunk(fd);
		return (*lst);
	}
	ret = *lst;
	while (ret)
	{
		if (ret->fd == fd)
			return (ret);
		if(ret->next == 0)
			break;
		ret = ret->next;
	}
	new = make_chunk(fd);
	ret->next = new;
	return (new);
}

char	*del_chunk(t_list **lst,t_list *chunk)
{
	t_list	*tmp;

	if(*lst == chunk)
	{
		*lst = (*lst)->next;
	}
	else
	{
		tmp = *lst;
		while (tmp->next != chunk)
			tmp = tmp->next;
		tmp->next = chunk->next;
	}
	free(chunk->bkup);
	free(chunk);
	chunk = 0;
	return (0);
}

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

char	*get_line_remains(t_list **lst,t_list *chunk)
{
	char		*remains;

	if (!*(chunk->bkup))
	{
		del_chunk(lst,chunk);
		return (0);
	}
	if (ft_strchr(chunk->bkup,'\n'))
	 	return (get_line_till_lf(&(chunk->bkup)));
	remains = ft_substr(chunk->bkup, 0, ft_strlen(chunk->bkup));
	del_chunk(lst, chunk);
	return (remains);
}

void	new_bkup(char **bkup,char *buf)
{
	char		*tmp_fre;

	tmp_fre = *bkup;
	*bkup = ft_strjoin(*bkup, buf);
	free(tmp_fre);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list			*chunk;
	char			buf[BUFFER_SIZE+1];
	int				rd_val;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	chunk = get_chunk(&lst, fd);
	if (chunk == 0)
		return (0);
	while (1)
	{
		rd_val = read(fd, buf, BUFFER_SIZE);
		if(rd_val < 0)
			return (del_chunk(&lst,chunk));
		buf[rd_val] = 0;
		new_bkup(&(chunk->bkup),buf);
		if(rd_val < BUFFER_SIZE)
			return (get_line_remains(&lst, chunk));
		if(ft_strchr(chunk->bkup,'\n'))
			return (get_line_till_lf(&(chunk->bkup)));
		
	}
	return (0);
}
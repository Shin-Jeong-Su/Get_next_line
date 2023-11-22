/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:57:46 by jeshin            #+#    #+#             */
/*   Updated: 2023/11/22 19:34:14 by jeshin           ###   ########.fr       */
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
	return (ret);
}

t_list	*get_chunk(t_list **lst, int fd)
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
		if (ret->next == 0)
			break ;
		ret = ret->next;
	}
	new = make_chunk(fd);
	ret->next = new;
	return (new);
}

char	*del_chunk(t_list **lst, t_list *chunk)
{
	t_list	*tmp;

	if (*lst == chunk)
		*lst = (*lst)->next;
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

char	*_get_line(t_list **lst, t_list *chunk)
{
	char		*ret;
	char		*tmp_fre;
	size_t		i;
	size_t		bkup_size;

	bkup_size = ft_strlen(chunk->bkup);
	if (ft_strchr(chunk->bkup, '\n'))
	{
		i = 0;
		while ((chunk->bkup)[i] && ((chunk->bkup))[i] != '\n')
			i++;
		ret = ft_substr((chunk->bkup), 0, (i + 1));
		tmp_fre = (chunk->bkup);
		if (bkup_size == i + 1)
			(chunk->bkup) = 0;
		else
			(chunk->bkup) = ft_substr(chunk->bkup, i + 1, bkup_size - (i + 1));
		free(tmp_fre);
		return (ret);
	}
	if (!*(chunk->bkup))
		return (del_chunk(lst, chunk));
	ret = ft_substr(chunk->bkup, 0, bkup_size);
	del_chunk(lst, chunk);
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list			*chunk;
	char			buf[BUFFER_SIZE + 1];
	int				rd_val;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	chunk = get_chunk(&lst, fd);
	if (chunk == 0)
		return (0);
	while (1)
	{
		rd_val = read(fd, buf, BUFFER_SIZE);
		if (rd_val < 0)
			return (del_chunk(&lst, chunk));
		buf[rd_val] = 0;
		if (new_bkup(&(chunk->bkup), buf) == 0)
			return (0);
		if (rd_val < BUFFER_SIZE || ft_strchr(chunk->bkup, '\n'))
			return (_get_line(&lst, chunk));
	}
	return (0);
}

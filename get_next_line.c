/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:54:39 by jeshin            #+#    #+#             */
/*   Updated: 2023/10/25 18:32:44 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str;
	size_t	size;
	int		rd;
	int		flg;

	size=BUFFER_SIZE;
	while(1)
	{
		str=(char *)malloc(sizeof(char)*size);
		if(!str)
			return (0);
		if(!(rd=read(fd,str,size)))
			return(0);
		char *end_str=ft_strchr(str,'\n');
		if(end_str)
			return(ft_strdup_till_c(str,'\n'));
		else
		{
			if(rd==-1)
				return (str);
			size*=2;
			flg=1;
			free(str);
		}

	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:55:12 by jeshin            #+#    #+#             */
/*   Updated: 2023/10/25 17:12:33 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_
#define GET_NEXT_LINE_
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 5

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup_till_c(const char *s, char c);
#endif
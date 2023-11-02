/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:54:39 by jeshin            #+#    #+#             */
/*   Updated: 2023/11/02 19:27:46 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//1. dup문제. 할당한거 또 복사? 주소값만 기억하면 반환가능.
//2. bfsize문제. bf사이즈 이상 들어오면 사이즈 키워서 읽고 이전에 읽은 것과 이어붙여야.
//static 어디서 사용? 왜사용? 0초기화. 프로그램종료까지 유지.개행을 찾으면 저장했던 문자열을 
//반환하는데 그 다음에 위치를 기억하기 위해서 static이 필요. 

//buffer size 만큼 읽어들이고 파일의 끝이 아닌데도 개행이 없다면 추가로읽어야하는데
//이부분을 나는 size 를 두배로 늘리는 방법을 생각했음.
//이전에 읽은 문자열을 백업시키고 사이즈를 두배로 다시 읽는데, read가 처음부터 다시읽는게 아니므로
//사이즈를 두배를 할 필요가 없음.

//ret의 메모리는 어떻게 할당할건지?
//buf랑 ret이 0로 끝나지 않음. 기존에 작성한 ft_strlen, ft_strchr, ft_strjoin
//적용가능?
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*ret;

	if (fd < 0 || (fd >= 1 && fd <= 2) || fd > OPEN_MAX)
		return (0);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	buf[BUFFER_SIZE] = 0;
	while (read(fd, buf, BUFFER_SIZE))
	{
		ret = ft_strjoin(ret, buf);
		if (ft_strchr(buf, '\n'))
		{
			return (get_line(&ret));
		}
	}
	return (0);
}

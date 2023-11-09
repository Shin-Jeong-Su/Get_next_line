#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	int i = 1;
	int fd;
	char *str;
	if (argc == 1)
	{
		printf("%s", get_next_line(0));
	}
	else
	{
		while (i < argc)
		{
			if ((fd = open(argv[i], O_RDONLY)) < 0)
				printf("%s is can't open", argv[i]);
			while ((str = get_next_line(fd)))
				printf("%s",str);
			i++;
		}
	}
}
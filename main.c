#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

void check_leak(void)
{
	system("leaks --list -- a.out");
}

int main(int argc, char **argv)
{
	int i;
	int fd;
	char *str;

	i = 1;
	if (argc == 1)
		printf("%s", get_next_line(0));
	else
	{
		while (i < argc)
		{
			if ((fd = open(argv[i], O_RDONLY)) < 0)
				printf("%s is can't open", argv[i]);
			while ((str = get_next_line(fd)))
			{
				//printf("%p",str);
				printf("%s", str);
			}
			i++;
		}
	}
	//atexit(check_leak);
	return (0);
}
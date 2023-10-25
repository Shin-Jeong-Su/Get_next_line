#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
int main(int argc,char **argv){
	if(argc==1){
		printf("%s\n",get_next_line(0));
	}
	else
	{
		while(**argv)
		{
			int fd = open(**argv,O_RDONLY);
			if (fd<0)
			{
				printf("%s file can't open",*argv);
			}
			get_next_line(fd);
			(*argv)++;
		}
	}
}
#include <stdio.h>
#include "get_next_line_bonus.h"
#include <fcntl.h>

int cnt;

void	check_leak(void)
{
	system("leaks --list -- a.out");
}

void	go(char **tab,int n)
{
	int *end_fd_tab = (int*)calloc(n,sizeof(int));
	int	*fd_tab = (int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		fd_tab[i]=open(tab[i+1],O_RDONLY);
	}
	while(cnt != n){
		for(int i=0;i<n;i++){
			if(end_fd_tab[i]){
				cnt++;
				continue;
			}
			char *str = get_next_line(fd_tab[i]);
			if(!str){
				end_fd_tab[i]=1;
				continue;
			}
			printf("%d -> %s\n",fd_tab[i],str);
		}
	}
	free(end_fd_tab);
	free(fd_tab);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
		printf("%s", get_next_line(0));
	go(argv,argc-1);
	atexit(check_leak);
	return (0);
}
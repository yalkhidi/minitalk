# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	handle_in(int sig)
{
	printf("\ncaught signal: %d\n", sig);
	exit(0);
}

void	handle_1(int sig)
{
	printf("sig: %d\n", sig);
	printf("SIGUSR1\n");
	exit(1);
}

void	handle_2(int sig)
{
	printf("sig: %d\n", sig);
	printf("SIGUSR2\n");
	exit(1);
}

int	main(void)
{
	signal(SIGUSR1, handle_1);
	signal(SIGUSR2, handle_2);
	signal(SIGINT, handle_in);
	printf("pid: %d\n", getpid());
	while (1)
		pause();
}
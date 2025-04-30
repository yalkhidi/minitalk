/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:45:01 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/30 22:06:28 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_in(int sig)
{
	ft_printf("\ncaught signal: %d\n", sig);
	exit(0);
}

// int	main(void)
// {
// 	pid_t	pid;

// 	pid = getpid();
// 	ft_printf("%d\n", pid);
// 	signal(SIGINT, handle_in);
// 	while (1)
// 		ft_printf("");
// }

void	handle_1(int sig)
{
	ft_printf("sig: %d\n", sig);
	ft_printf("SIGUSR1\n");
	exit(1);
}

void	handle_2(int sig)
{
	ft_printf("sig: %d\n", sig);
	ft_printf("SIGUSR2\n");
	exit(1);
}

int	main(void)
{
	signal(SIGUSR1, handle_1);
	signal(SIGUSR2, handle_2);
	signal(SIGINT, handle_in);
	ft_printf("pid: %d", getpid());
	while (1)
		pause();
}

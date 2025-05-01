/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:45:01 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/05/01 17:55:14 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_in(int sig)
{
	ft_printf("\ncaught signal: %d\n", sig);
	exit(0);
}

// void	handle_1(int sig)
// {
// 	ft_printf("sig: %d\n", sig);
// 	ft_printf("SIGUSR1\n");
// 	exit(1);
// }

// void	handle_2(int sig)
// {
// 	ft_printf("sig: %d\n", sig);
// 	ft_printf("SIGUSR2\n");
// 	exit(1);
// }

void	receive_message(int sig)
{
	static int	bits[8];
	static int	bit_index = 0;
	int			i;
	char		letter;

	if (sig == SIGUSR1)
	{
		bits[bit_index] = 1;
		printf("received 1\n");
	}
	else if(sig == SIGUSR2)
	{
		bits[bit_index] = 0;
		printf("received 0\n");
	}
	bit_index++;
	if(bit_index == 8)
	{
		letter = 0;
		i = 0;
		while(i < 8)
		{
			letter = letter * 2 + bits[i];
			i++;
		}
		ft_printf("%c", letter);
		bit_index = 0;
	}
}



int	main(void)
{
	// signal(SIGUSR1, handle_1);
	// signal(SIGUSR2, handle_2);
	signal(SIGINT, handle_in);
	signal(SIGUSR1, receive_message);
	signal(SIGUSR2, receive_message);
	ft_printf("pid: %d\n", getpid());
	while (1)
		pause();
}

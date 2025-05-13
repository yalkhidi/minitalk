/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:45:01 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/05/07 11:33:22 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_in(int sig)
{
	ft_printf("\nCaught signal: %d\n", sig);
	exit(0);
}

void	receive_message(int sig)
{
	static int	bits[8];
	static int	bit_index = 7;
	char		letter;
	int			i;

	if (sig == SIGUSR1)
		bits[bit_index] = 1;
	else if (sig == SIGUSR2)
		bits[bit_index] = 0;
	bit_index--;
	if (bit_index < 0)
	{
		letter = 0;
		i = 0;
		while (i < 8)
		{
			letter <<= 1;
			letter |= bits[i];
			i++;
		}
		if (letter == '\0')
			ft_printf("\n");
		ft_printf("%c", letter);
		bit_index = 7;
	}
}

int	main(void)
{
	signal(SIGINT, handle_in);
	signal(SIGUSR1, receive_message);
	signal(SIGUSR2, receive_message);
	ft_printf("pid: %d\n", getpid());
	while (1)
		pause();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:45:01 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/05/06 14:26:44 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

void	handle_in(int sig)
{
	ft_printf("\nCaught signal: %d\n", sig);
	exit(0);
}

char	binary_to_char(int *bits)
{
	char	letter;
	int		i;

	i = 0;
	letter = 0;
	while (i < 8)
	{
		letter <<= 1;
		letter |= bits[i];
		i++;
	}
	return (letter);
}

void	receive_message(int sig, siginfo_t *info, void *content)
{
	static int	bits[8];
	static int	bit_index = 7;
	char		letter;

	(void)content;
	if (sig == SIGUSR1)
		bits[bit_index] = 1;
	else if (sig == SIGUSR2)
		bits[bit_index] = 0;
	bit_index--;
	if (bit_index < 0)
	{
		letter = binary_to_char(bits);
		if (letter == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR1);
		}
		ft_printf("%c", letter);
		bit_index = 7;
	}
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("%d\n", getpid());
	action.sa_sigaction = receive_message;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	signal(SIGINT, handle_in);
	while (1)
		pause();
}

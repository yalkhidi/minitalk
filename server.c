/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:45:01 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/05/01 19:34:35 by yalkhidi         ###   ########.fr       */
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


char	b_to_c(int	*bin)
{
	char	result;
	int				i;
	
	result = 0;
	i = 0;
	while (i < 8)
	{
		result = (result << 1) | (bin[i] & 1);
		i++;
	}
	return(result);
}

void	receive_message(int sig)
{
	static int	bits[8];
	static int	bit_index = 7;
	int			i;
	char		letter;

	if (sig == SIGUSR1)
		bits[bit_index] = 1;
	else if(sig == SIGUSR2)
		bits[bit_index] = 0;
	bit_index--;
	if(bit_index < 0)
	{
		letter = 0;
		i = 0;
		while(i < 8)
		{
			letter = letter * 2 + bits[i];
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
	// signal(SIGUSR1, handle_1);
	// signal(SIGUSR2, handle_2);
	signal(SIGINT, handle_in);
	signal(SIGUSR1, receive_message);
	signal(SIGUSR2, receive_message);
	ft_printf("pid: %d\n", getpid());
	while (1)
		pause();
}

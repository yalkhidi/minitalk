/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:43:48 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/05/01 19:19:01 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(pid_t pid, char letter)
{
	int		j;
	char	let[8];

	j = 7;
	while (j >= 0)
	{
		if (letter % 2 == 1)
		{
			let[j] = '1';
			kill(pid, SIGUSR1);
		}
		else if (letter % 2 == 0)
		{
			let[j] = '0';
			kill(pid, SIGUSR2);
		}
		letter = letter / 2;
		usleep(300);
		j--;
	}
	ft_printf("%s\n", let);
}



int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;
	int		i;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		message = av[2];
		ft_printf("pid: %d\n", pid);
		ft_printf("message: %s\n", message);
		i = 0;
		while (message[i])
		{
			send_message(pid, message[i]);
			i++;
		}
		send_message(pid, '\0');
	}
	else
		ft_printf("wrong format\n");
}

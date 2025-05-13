/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:43:48 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/05/07 11:37:20 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(pid_t pid, char letter)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if ((letter & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		letter = letter >> 1;
		usleep(500);
		j--;
	}
}

pid_t	get_pid(char *av)
{
	int	pid;

	if (!check(av))
	{
		ft_printf("Non numeric pid\n");
		exit(1);
	}
	else
	{
		pid = ft_atoi(av);
		if (pid <= 0)
		{
			ft_printf("Invalid pid\n");
			exit(1);
		}
		return (pid);
	}
}

void	print_message(int sig)
{
	(void)sig;
	ft_printf("Message received\n");
	exit(0);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;
	int		i;

	signal(SIGUSR1, print_message);
	if (ac == 3)
	{
		pid = get_pid(av[1]);
		if (kill(pid, 0) == -1)
		{
			ft_printf("Invalid PID");
			exit(1);
		}
		message = av[2];
		i = 0;
		while (message[i])
		{
			send_message(pid, message[i]);
			i++;
		}
		send_message(pid, '\0');
		pause();
	}
	else
		ft_printf("Usage: ./client_bonus <pid> <string_to_send> \n");
}

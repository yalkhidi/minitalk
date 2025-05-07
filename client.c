/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:43:48 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/05/06 20:07:20 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ft_printf/ft_printf.h"

int	ft_atoi(const char *str)
{
	int	output;
	int	sign;
	int	i;

	output = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		output = (output * 10) + (str[i] - '0');
		i++;
	}
	return (sign * output);
}

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
bool check_pid(char *av)
{
	int		i;
	
	i = 0;
	while(av[i])
	{
		ft_printf("while\n");
		if (!(av[i] >= '0' && av[i] <= '9') && (av[i] != '+'))
			return (false);
		i++;
	}
	return (true);
}

pid_t	get_pid(char *av)
{
	int	pid;

	if (!check_pid(av))
	{
		ft_printf("pid is non numeric\n");
		exit(1);
	}
	else
	{
		pid = ft_atoi(av);
		// if (pid <= 0)
		// {
		// 	ft_printf("Invalid pid\n");
		// 	exit(1);
		// }
		return (pid);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;
	int		i;

	if (ac == 3)
	{
		pid = get_pid(av[1]);
		ft_printf("pid %d", pid);
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
	}
	else
		ft_printf("Usage: ./client <pid> <string_to_send> \n");
}

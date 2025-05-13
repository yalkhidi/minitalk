/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:29:21 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/05/07 12:17:08 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

bool	ft_isdigit(char d)
{
	if (d >= '0' && d <= '9')
		return (true);
	return (false);
}

bool	check(char *av)
{
	int	i;

	i = 0;
	while ((av[i] == ' ' || av[i] == '\t' ) && av[i])
		i++;
	if (av[i] == '\0')
		return (false);
	if (av[i] == '-' || av[i] == '+')
	{
		if (!ft_isdigit(av[i + 1]))
			return (false);
		i++;
	}
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (false);
		i++;
	}
	return (true);
}

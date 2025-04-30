/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:45:01 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/30 11:53:38 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_in(int sig)
{
	ft_printf("caught signal: %d\n", sig);
	exit(0);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGINT, handle_in);
	while (1)
		ft_printf("");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:24:55 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/01/02 11:29:54 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, c);
	n = n % 16;
	if ((n > 9) && (n < 16))
	{
		if (c == 'x')
			n = 'a' + (n - 10);
		else if (c == 'X')
			n = 'A' + (n - 10);
	}
	else
		n = n + '0';
	ft_putchar(n);
	len++;
	return (len);
}

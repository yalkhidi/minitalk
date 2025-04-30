/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:31:01 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/01/05 12:57:31 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(uintptr_t num)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_putaddress(num / 16);
	num = num % 16;
	if ((num > 9) && (num < 16))
		num = 'a' + (num - 10);
	else
		num = num + '0';
	len += ft_putchar(num);
	return (len);
}

int	ft_putvoid(void *p)
{
	uintptr_t	addr;
	int			len;

	addr = (uintptr_t)p;
	len = 0;
	len += ft_putstr("0x");
	len += ft_putaddress(addr);
	return (len);
}

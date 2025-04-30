/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:44:55 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/01/06 16:05:11 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifiers(va_list a, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(a, int));
	else if (c == '%')
		len += ft_putchar('%');
	else if (c == 's')
		len += ft_putstr(va_arg(a, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(a, int));
	else if (c == 'u')
		len += ft_putunsigned(va_arg(a, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_puthex(va_arg(a, unsigned int), c);
	else if (c == 'p')
		len += ft_putvoid(va_arg(a, void *));
	return (len);
}

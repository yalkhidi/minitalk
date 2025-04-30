/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:27:22 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/01/05 11:26:43 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	list;
	int		char_printed;

	i = 0;
	char_printed = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			char_printed += ft_specifiers(list, str[i + 1]);
			i++;
		}
		else
			char_printed += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (char_printed);
}

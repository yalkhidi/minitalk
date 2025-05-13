/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:30:00 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/05/07 11:34:12 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include "ft_printf/ft_printf.h"

int		ft_atoi(const char *str);
bool	ft_isdigit(char d);
bool	check(char *av);
#endif
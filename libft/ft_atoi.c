/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:41:16 by mperseus          #+#    #+#             */
/*   Updated: 2019/12/23 00:18:37 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_calc(const char *str, int sign)
{
	size_t	res;

	res = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = res * 10 + *str - '0';
		str++;
	}
	if (res > 9223372036854775807)
		return (sign ? 0 : -1);
	return (sign ? -res : res);
}

int				ft_atoi(const char *str)
{
	int		sign;

	while (*str && (*str == '\t' || *str == '\n' || *str == '\v' ||
				*str == '\r' || *str == '\f' || *str == ' '))
		str++;
	sign = 0;
	if (*str == '-')
	{
		sign = 1;
		str++;
		if (*str < '0' || *str > '9')
			return (0);
	}
	if (*str == '+')
	{
		str++;
		if (*str < '0' || *str > '9')
			return (0);
	}
	return (ft_calc(str, sign));
}

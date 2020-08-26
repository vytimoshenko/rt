/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:54:54 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/01 21:55:15 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int power)
{
	int a;
	int b;

	if (power < 0)
		return (0);
	if (power > 0)
	{
		a = nb;
		b = power;
		while (power > 1)
		{
			a = nb * a;
			power--;
		}
		return (a);
	}
	else
		return (1);
}

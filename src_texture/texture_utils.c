/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 21:16:28 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/14 21:16:28 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_clr	integer_to_rgb(int clr)
{
	return (t_clr){(clr >> 16) & 255, (clr >> 8) & 255, clr & 255};
}

int		rgb_to_integer(t_clr clr)
{
	return ((clr.r << 16) | (clr.g << 8) | clr.b);
}
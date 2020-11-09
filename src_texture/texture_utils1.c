/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 21:16:28 by wquirrel          #+#    #+#             */
/*   Updated: 2020/11/09 20:38:26 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

double	f(double t)
{
	t = fabs(t);
	return (t >= 1.0f ? 0.0f : 1.0f - (3.0f - 2.0 * t) * t * t);
}

double	surflet(t_double2 uv, double grad_x, double grad_y)
{
	return (f(uv.u) * f(uv.v) * (grad_x * uv.u + grad_y * uv.v));
}

t_clr	integer_to_rgb(int clr)
{
	return ((t_clr){(clr >> 16) & 255, (clr >> 8) & 255, clr & 255});
}

int		rgb_to_integer(t_clr clr)
{
	return ((clr.r << 16) | (clr.g << 8) | clr.b);
}

void	free_texture(t_texture *t)
{
//	Заглушка
	if (t)
		return ;
// TODO при втором нажатии на R вылетает сега
// TODO попробовать очистку через mlx_destroy_image()
/*	free(t->addr);
	free(t->data);
	free(t->name);*/
}

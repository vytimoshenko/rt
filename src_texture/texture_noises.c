/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_noises.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:36:12 by wquirrel          #+#    #+#             */
/*   Updated: 2020/11/09 20:38:13 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

int		perlin_noise(t_obj *obj)
{
	double n;

	n = noise((t_double2){obj->uv.u * 100, obj->uv.v * 100}, 0);
	n = 0.5 * (n + 1.0);
	return (rgb_to_integer((t_clr){
		255 * n,
		255 * n,
		255 * n}));
}

int		wood(t_obj *obj)
{
	double	n;
	double	period;
	double	sine;
	t_clr	clr;

	period = 10;
	n = noise((t_double2){obj->uv.u * 10, obj->uv.v * 5}, 0);
	sine = 128.0 * fabs(sin(2 * period * n * M_PI));
	clr = (t_clr){
			80 + sine,
			30 + sine,
			30
	};
	return (rgb_to_integer((t_clr){clr.r, clr.g, clr.b}));
}

int		marble(t_obj *obj)
{
	double	n;
	double	sine;
	t_clr	clr;

	n = noise((t_double2){obj->uv.u * 16, obj->uv.v * 32}, 0);
	sine = 256.0 * fabs(sin(n * M_PI));
	clr = (t_clr){
			sine,
			sine,
			sine
	};
	return (rgb_to_integer((t_clr){clr.r, clr.g, clr.b}));
}

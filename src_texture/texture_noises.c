/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_perline_noise.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:36:12 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/28 21:16:46 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

int		perlin_noise(t_obj *obj)
{
	double n;
	n = noise((t_double2){obj->uv.u * 100, obj->uv.v * 1000}, 0);
	n = 0.5 * (n + 1.0);
	return rgb_to_integer((t_clr){
		255 * n,
		255 * n,
		255 * n});
}

int		wood(t_obj *obj)
{
	double n;
	double period;

	period = 10;
	n =  noise((t_double2){obj->uv.u * 10, obj->uv.v * 5}, 0);
//	n = n - floor(n);
//	n = 0.5 * (n + 1.0);
	double sine = 128.0 * fabs(sin(2 * period * n * M_PI));
	t_clr clr = {
			80 + sine,
			30 + sine,
			30
	};
//	t_double2 uv = {obj->uv.u * obj->uv.u * n, obj->uv.v * obj->uv.v * n};
//	int clr = stripe_pattern(obj, obj->uv, mat);

	return rgb_to_integer((t_clr){clr.r, clr.g, clr.b});
//	return stripe_pattern(obj, uv, mat);
}

int		marble(t_obj *obj)
{
	double n;
	n =  noise((t_double2){obj->uv.u * 16, obj->uv.v * 32}, 0);
//	n = n - floor(n);
//	n = 0.5 * (n + 1.0);
	double sine = 256.0 * fabs(sin(n * M_PI));
	t_clr clr = {
			sine,
			sine,
			sine
	};
//	t_double2 uv = {obj->uv.u * obj->uv.u * n, obj->uv.v * obj->uv.v * n};
//	int clr = stripe_pattern(obj, obj->uv, mat);

	return rgb_to_integer((t_clr){clr.r, clr.g, clr.b});
//	return stripe_pattern(obj, uv, mat);
}

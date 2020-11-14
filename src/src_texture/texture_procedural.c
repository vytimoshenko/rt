/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_procedural.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:48:06 by wquirrel          #+#    #+#             */
/*   Updated: 2020/11/09 20:38:22 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/rt.h"

int		wave_pattern(t_double2 uv, t_mat *mat)
{
	double u;
	double v;
	double sines;

	u = uv.u * WAVE_SIZE;
	v = uv.v * WAVE_SIZE;
	sines = sin(u * 1.51 + v * 0.502);
	if (sines < 0)
		return (rgb_to_integer(mat->color));
	else
		return (T_COLOR_BL);
}

int		plane_checker_pattern(t_pnt *pnt, t_obj *obj)
{
	t_double2	uv;
	double		sines;
	int			color;

	uv = get_plane_texel_g(obj, pnt);
	sines = sin(uv.u) * sin(uv.v);
	if (sines < 0)
		color = (T_COLOR_W);
	else
		color = (T_COLOR_BL);
	return (color);
}

int		checker_pattern(t_double2 uv, t_pnt *pnt, t_obj *obj)
{
	int u2;
	int v2;
	int color;

	if (obj->type == OBJECT_TYPE_PLANE)
		return (plane_checker_pattern(pnt, obj));
	color = 0;
	u2 = floor(uv.u * CHECKER_W);
	v2 = floor(uv.v * CHECKER_H);
	if (obj->type == OBJECT_TYPE_CYLINDER || obj->type == OBJECT_TYPE_CONE)
	{
		u2 = floor(uv.u * CHECKER_W);
		v2 = floor(uv.v * CHECKER_H * 2);
	}
	if ((u2 + v2) % 2 == 0)
		color = T_COLOR_W;
	else
		color = T_COLOR_BL;
	return (color);
}

int		stripe_pattern_plane(t_double2 uv, int pat)
{
	double tmp;
	double sines;

	tmp = pat == 1 ? uv.u : uv.v;
	sines = sin(M_PI * tmp / STRIPE);
	if (sines < 0.15)
		return (T_COLOR_W);
	else
		return (T_COLOR_BL);
}

int		stripe_pattern(t_obj *obj, t_double2 uv, t_mat *mat)
{
	int u;
	int v;
	int p;

	u = floor(uv.u * STRIPE);
	v = floor(uv.v * STRIPE);
	p = mat->pattern == 1 ? u : v;
	if (obj->type == OBJECT_TYPE_PLANE)
		return (stripe_pattern_plane(uv, mat->pattern));
	if (p % 2 == 0)
		return (rgb_to_integer(mat->color));
	else
		return (T_COLOR_BL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_procedural.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:48:06 by wquirrel          #+#    #+#             */
/*   Updated: 2020/09/30 17:18:15 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

int		plane_checker_pattern(t_pnt *pnt, t_obj *obj)
{
//	t_vec tmp = mult(3 ,pnt->xyz);
//	t_vec tmp = sub(pnt->xyz, obj->pos);
//	double sins = sin(10 * tmp.x) * sin(10 * tmp.y) * sin(10 * tmp.z);
	t_double2 uv = get_plane_texel(obj, pnt);
	double sins = sin(uv.u) * sin(uv.v);
	int color;

	if (obj)
		color = 0;

	if (sins < 0)
		color = T_COLOR_W;
	else
		color = T_COLOR_BL;
	return (color);
}

int		checker_pattern(t_double2 uv)
{
	int u2 = floor(uv.u * CHECKER_W);
	int v2 = floor(uv.v * CHECKER_H);
	int color = 0;

	if ((u2 + v2) % 2  == 0)
		color = T_COLOR_W;
	else
		color = T_COLOR_BL;
	return (color);
}

int		stripe_pattern(t_pnt *pnt, t_obj *obj)
{
	double xyz;

	xyz = obj->pattern == 1 ? pnt->n.x : obj->pattern == 2 ? pnt->n.y
														   : pnt->n.z;
	if (obj->type != OBJECT_TYPE_PLANE)
		xyz *= obj->radius;
	else
	{
		t_vec n_xyz = sub(pnt->xyz, obj->pos);
		xyz += obj->pattern == 1 ? n_xyz.x : obj->pattern == 2 ? n_xyz.y
																  : n_xyz.z;
	}

	if ((int )floor(xyz) % 2 == 0)
		return T_COLOR_W;
	else
		return T_COLOR_BL;
}

int		choose_pattern(t_pnt *pnt, t_obj *obj, t_double2 uv)
{
	if (obj->pattern >= STRIPE_X && obj->pattern <= STRIPE_Z)
		return stripe_pattern(pnt, obj);
	else if (obj->pattern == CHECKER)
	{
		if (obj->type == OBJECT_TYPE_PLANE)
			return plane_checker_pattern(pnt, obj);
		return checker_pattern(uv);
	}
	return (0);
}
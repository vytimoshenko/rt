/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_procedural.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:48:06 by wquirrel          #+#    #+#             */
/*   Updated: 2020/09/25 19:18:50 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

/*
int		checker_pattern(t_pnt *pnt, t_obj *obj)
{

	t_vec tmp = mult(3 ,pnt->xyz);
	double sins = sin(tmp.x) * sin(tmp.y) * sin(tmp.z);
	int color;

	if (obj)
		color = 0;

	if (sins < 0)
		color = T_COLOR_W;
	else
		color = T_COLOR_BL;
	return (color);
}
*/
int		checker_pattern(t_uv uv)
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

int		choose_pattern(t_pnt *pnt, t_obj *obj, t_uv uv)
{
	if (obj->pattern >= STRIPE_X && obj->pattern <= STRIPE_Z)
		return stripe_pattern(pnt, obj);
	else if (obj->pattern == CHECKER)
		return checker_pattern(uv);
	return (0);
}
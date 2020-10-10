/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_procedural.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:48:06 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/10 20:18:50 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

int		plane_checker_pattern(t_pnt *pnt, t_obj *obj)
{
//	t_vec tmp = mult(3 ,pnt->xyz);
//	t_vec tmp = sub(pnt->xyz, obj->pos);
//	double sines = sin(10 * tmp.x) * sin(10 * tmp.y) * sin(10 * tmp.z);
	t_double2 uv = get_plane_texel_g(obj, pnt);
	double sines = sin(uv.u) * sin(uv.v);
	int color;

	if (obj)
		color = 0;

	if (sines < 0)
		color = T_COLOR_W;
	else
		color = T_COLOR_BL;
	return (color);
}

int		checker_pattern(t_double2 uv, t_pnt *pnt, t_obj *obj)
{
	if (obj->type == OBJECT_TYPE_PLANE)
		return plane_checker_pattern(pnt, obj);

	int u2 = floor(uv.u * CHECKER_W);
	int v2 = floor(uv.v * CHECKER_H);

	if (obj->type == OBJECT_TYPE_CYLINDER || obj->type == OBJECT_TYPE_CONE)
	{
		u2 = floor(uv.u * CHECKER_W);
		v2 = floor(uv.v * CHECKER_H * 2);
	}

	int color = 0;

	if ((u2 + v2) % 2  == 0)
		color = T_COLOR_W;
	else
		color = T_COLOR_BL;
	return (color);
}

int 	stripe_pattern_plane(t_pnt *pnt, t_obj *obj, t_double2 uv)
{
/*	double  xyz;
	xyz = obj->pattern == 1 ? pnt->n.x : obj->pattern == 2 ? pnt->n.y
														   : pnt->n.z;
	t_vec n_xyz = sub(pnt->xyz, obj->pos);

	xyz += obj->pattern == 1 ? n_xyz.x : obj->pattern == 2 ? n_xyz.y: n_xyz.z;

	if (fmod(xyz, 4) == 0)
		return T_COLOR_W;
	else
		return T_COLOR_BL;*/
//	t_double2 uv1 = get_plane_texel_l(obj, pnt);
	double tmp = obj->pattern == 1 ? uv.u : uv.v;
//	printf("%f\n", tmp);
	double sines = 	sin(M_PI * tmp / STRIPE);
//	double sines = sin(uv.u) * sin(uv.v);

	if (sines < 0.15)
		return T_COLOR_W;
	else
		return T_COLOR_BL;
/*	printf("u:%f\n",uv.u);
	printf("v:%f\n",uv.v);

//	double tmp = obj->pattern == 1 ? uv.u : uv.v;
	double tmp = uv.u;
	if (tmp < 0.5 )
		return T_COLOR_W;
	else
		return T_COLOR_BL;*/
}

int		stripe_pattern(t_pnt *pnt, t_obj *obj, t_double2 uv)
{
/*	double xyz;

	xyz = obj->pattern == 1 ? pnt->n.x : obj->pattern == 2 ? pnt->n.y
														   : pnt->n.z;
	if (obj->type != OBJECT_TYPE_PLANE)
		xyz *= obj->radius;
	else
	{
		t_vec n_xyz = sub(pnt->xyz, obj->pos);
		xyz += obj->pattern == 1 ? n_xyz.x : obj->pattern == 2 ? n_xyz.y: n_xyz.z;
	}*/
	if (obj->type == OBJECT_TYPE_PLANE)
		return (stripe_pattern_plane(pnt, obj, uv));

	int u = floor(uv.u * STRIPE);
	int v = floor(uv.v * STRIPE);
	int p = obj->pattern == 1 ? u : v;

	if (p % 2 == 0)
		return T_COLOR_W;
	else
		return T_COLOR_BL;
}

int		choose_pattern(t_pnt *pnt, t_obj *obj, t_double2 uv)
{
	if (obj->pattern >= STRIPE_X && obj->pattern <= STRIPE_Y)
		return stripe_pattern(pnt, obj, uv);
	else if (obj->pattern == CHECKER)
		return checker_pattern(uv, pnt, obj);
	return (0);
}
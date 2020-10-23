/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_procedural.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:48:06 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/19 21:16:49 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

int		wave_pattern(t_double2 uv, t_mat *mat)
{

	double u = uv.u  * 50;
	double v = uv.v  * 50;
	double sines = sin(u * 1.51 + v * 0.502);

	if (sines < 0)
		return rgb_to_integer(mat->color);
	else
		return T_COLOR_BL;

/*	double u = uv.u * STRIPE;
	double v = uv.v * STRIPE;
	double sines = sin(u + v);
	t_clr clr = {mat->color.r * sines
			  , mat->color.g * sines
			  , mat->color.b * sines};
	return rgb_to_integer((t_clr){clr.r, clr.g, clr.b});*/
}

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

int stripe_pattern_plane(t_obj *obj, t_double2 uv, int pat)
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
	double tmp = pat == 1 ? uv.u : uv.v;
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

int stripe_pattern(t_obj *obj, t_double2 uv, t_mat *mat)
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
		return (stripe_pattern_plane(obj, uv, mat->pattern));

	int u = floor(uv.u * STRIPE);
	int v = floor(uv.v * STRIPE);
	int p = mat->pattern == 1 ? u : v;

	if (p % 2 == 0)
		return rgb_to_integer(mat->color);
//		return T_COLOR_W;
	else
		return T_COLOR_BL;
}


int get_patt_color(t_pnt *pnt, t_obj *obj, t_double2 uv, t_mat *mat)
{
	if (mat->pattern >= STRIPE_X && mat->pattern <= STRIPE_Y)
		return stripe_pattern(obj, uv, mat);
	else if (mat->pattern == CHECKER)
		return checker_pattern(uv, pnt, obj);
	else if (mat->pattern == WAVE)
		return wave_pattern(uv, mat);
	else if (mat->pattern == PERLIN_N)
		return perlin_noise(obj);
	return (0);
}
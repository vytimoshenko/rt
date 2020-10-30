/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:26:09 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/28 21:44:21 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			get_cyco_uv(t_pnt *p, t_obj *obj, t_double2 *uv, int k)
{
	t_vec		u;
	t_vec		v;
	t_vec		tmp2;
	t_vec		loc;
	t_double2	theta_raw_u;

	u = get_texture_dir(nrm(obj->dir));
	v = cross_product(u, nrm((obj->dir)));
	//	TODO можно смещать и расширять текстуры
	loc = mult(-1 / obj->radius, sub(p->xyz, obj->pos));
	tmp2.x = dot(loc, u);
	tmp2.y = dot(loc, obj->dir);
	tmp2.z = dot(loc, v);
	if (obj->type == OBJECT_TYPE_CYLINDER)
		tmp2.y *= -1;
	if (obj->type == OBJECT_TYPE_CONE)
		tmp2.z *= -1;
	theta_raw_u.u = atan2(tmp2.x, tmp2.z);
	theta_raw_u.v = theta_raw_u.u / (2 * M_PI);
	uv->u = 1 - (theta_raw_u.v + 0.5);
	uv->v = fmod(tmp2.y, k) / k;
	if (uv->v < 0)
		uv->v += 1;
}

void			get_sphere_uv(t_pnt *p, t_obj *obj, t_double2 *uv)
{
	t_vec	tmp;
	double	phi;
	double	theta;

//	TODO можно переворачивать текстур на объекте меняя местами z, x и у
//	TODO или можно менять знак у координат
//	TODO Умножая phi and theta можно сжимать и расширять текстуры
	tmp = mult(1 / obj->radius, sub(p->xyz, obj->pos));
	phi = atan2(tmp.z, -tmp.x);
	theta = asin(tmp.y);
	uv->u = 1 - (phi + M_PI) / (2 * M_PI);
	uv->v = (theta + M_PI / 2) / M_PI;
}

t_double2		get_plane_texel_l(t_obj *obj, t_pnt *p)
{
	t_double2	uv;
	t_vec		u;
	t_vec		v;

	u = get_texture_dir(nrm(obj->pos));
	v = cross_product(nrm(obj->pos), u);
	uv.u = dot(u, sub(p->xyz, obj->pos));
	uv.v = dot(v, sub(p->xyz, obj->pos));
	return (uv);
}

void			get_plane_uv(t_pnt *p, t_obj *obj, t_double2 *uv)
{
	int			k;
	t_double2	uv1;

	k = 16;
	uv1 = get_plane_texel_l(obj, p);
	uv->u = fmod(uv1.u, k) / (double)k;
	uv->v = fmod(uv1.v, k) / (double)k;
	if (uv->u < 0)
		uv->u = 1 + uv->u;
	if (uv->v < 0)
		uv->v = 1 + uv->v;
}

void			get_uv(t_pnt *p, t_obj *obj, t_double2 *uv)
{
	if (obj->type == OBJECT_TYPE_PLANE)
		get_plane_uv(p, obj, uv);
	else if (obj->type == OBJECT_TYPE_SPHERE)
		get_sphere_uv(p, obj, uv);
	else if (obj->type == OBJECT_TYPE_CYLINDER || obj->type == OBJECT_TYPE_CONE)
		get_cyco_uv(p, obj, uv, 10);
}

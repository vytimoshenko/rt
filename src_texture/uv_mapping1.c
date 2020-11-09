/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_mapping1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:26:09 by wquirrel          #+#    #+#             */
/*   Updated: 2020/11/09 20:38:34 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void			get_cyco_uv(t_pnt *p, t_obj *obj, int k, t_mat *mat)
{
	t_vec		u;
	t_vec		v;
	t_vec		tmp;
	t_vec		loc;
	t_double2	theta_raw_u;

	u = get_texture_dir(nrm(obj->dir));
	v = cross_product(u, nrm((obj->dir)));
	loc = mult(-1 / obj->radius, sub(p->xyz, obj->pos));
	tmp.x = dot(loc, u);
	tmp.y = dot(loc, obj->dir);
	tmp.z = dot(loc, v);
	if (obj->type == OBJECT_TYPE_CYLINDER)
		tmp.y *= -1;
	if (obj->type == OBJECT_TYPE_CONE)
		tmp.z *= -1;
	tmp = (t_vec){tmp.x * (mat->shift.x != 0 ? -1 : 1),
		tmp.y * (mat->shift.y != 0 ? -1 : 1),
		tmp.z * (mat->shift.z != 0 ? -1 : 1)};
	k += ft_clamp((int)mat->scale, 1, 100);
	theta_raw_u.u = atan2(tmp.x, tmp.z);
	theta_raw_u.v = theta_raw_u.u / (2 * M_PI);
	obj->uv = (t_double2){1 - (theta_raw_u.v + 0.5), fmod(tmp.y, k) / k};
	if (obj->uv.v < 0)
		obj->uv.v += 1;
}

void			get_sphere_uv(t_pnt *p, t_obj *obj, t_double2 *uv, t_mat *mat)
{
	t_vec	tmp;
	double	phi;
	double	theta;
	double	scale;

	scale = ft_clamp(mat->scale, 1, 5);
	tmp = mult(1 / obj->radius, sub(p->xyz, obj->pos));
	tmp = (t_vec){tmp.x *= mat->shift.x != 0 ? -1 : 1,
		tmp.y *= mat->shift.y != 0 ? -1 : 1,
		tmp.z *= mat->shift.z != 0 ? -1 : 1};
	phi = atan2(tmp.z / scale, -tmp.x / scale);
	theta = asin(tmp.y / scale);
	uv->u = 1 - (phi + M_PI) / (2 * M_PI);
	uv->v = (theta + M_PI / 2) / M_PI;
}

t_double2		get_plane_texel_l(t_obj *obj, t_pnt *p, t_mat *mat)
{
	t_double2	uv;
	t_vec		u;
	t_vec		v;
	t_vec		new_pos;

	new_pos = (t_vec){obj->pos.x + mat->shift.x,
				obj->pos.y + mat->shift.y,
				obj->pos.z + mat->shift.z};
	u = get_texture_dir(nrm(obj->dir));
	v = cross_product(nrm(obj->dir), u);
	uv.u = dot(u, sub(p->xyz, new_pos));
	uv.v = dot(v, sub(p->xyz, new_pos));
	return (uv);
}

void			get_plane_uv(t_pnt *p, t_obj *obj, t_double2 *uv, t_mat *mat)
{
	int			k;
	t_double2	uv1;

	k = ft_clamp((int)mat->scale, 8, 100);
	uv1 = get_plane_texel_l(obj, p, mat);
	uv->u = fmod(uv1.u, k) / (double)k;
	uv->v = fmod(uv1.v, k) / (double)k;
	if (uv->u < 0)
		uv->u = 1 + uv->u;
	if (uv->v < 0)
		uv->v = 1 + uv->v;
}

void			get_uv(t_pnt *p, t_obj *obj, t_double2 *uv, t_mat *mat)
{
	if (obj->type == OBJECT_TYPE_PLANE)
		get_plane_uv(p, obj, uv, mat);
	else if (obj->type == OBJECT_TYPE_SPHERE)
		get_sphere_uv(p, obj, uv, mat);
	else if (obj->type == OBJECT_TYPE_CYLINDER || obj->type == OBJECT_TYPE_CONE)
		get_cyco_uv(p, obj, 8, mat);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:26:09 by wquirrel          #+#    #+#             */
/*   Updated: 2020/09/30 18:50:09 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

t_vec	cross_product(t_vec a, t_vec b)
{
	double i = a.y * b.z - a.z * b.y;
	double j = a.z * b.x - a.x * b.z;
	double k = a.x * b.y - a.y * b.x;
	return (t_vec){i, j , k};
}

t_vec	compute_primary_tex_dir(t_vec n)
{
	t_vec a = cross_product(n, (t_vec){1, 0, 0});
	t_vec b = cross_product(n, (t_vec){0, 1, 0});

	t_vec max_ab = dot(a, a) < dot(b, b) ? b : a;

	t_vec c = cross_product(n, (t_vec){0, 0, 1});
	return nrm(dot(max_ab, max_ab) < dot(c, c) ? c : max_ab);
}

void	get_cylinder_uv(t_pnt *p, t_obj *obj, t_double2 *uv)
{
	int k = 8;
//	t_vec tmp = mult(1 / obj->radius, sub(p->xyz, obj->pos));
	t_vec u = compute_primary_tex_dir(nrm(obj->dir));
	t_vec v = cross_product(u, nrm((obj->dir)));
	t_vec tmp2;
//	t_vec loc = nrm(sub(p->xyz, obj->pos));
	t_vec loc = mult(1 / obj->radius, sub(p->xyz, obj->pos));;
	tmp2.x = dot(loc, u);
	tmp2.y = dot(loc, obj->dir);
	tmp2.z = dot(loc, v);
	double theta = atan2(tmp2.x, tmp2.z);
	double raw_u = theta / (2 * M_PI);
	uv->u = 1 - (raw_u + 0.5);
	uv->v = fmod(tmp2.y, k) / k;

//	uv->v = fmod(tmp.y, (2 * M_PI) * 1 / (double )(2 * M_PI)) / k;
}

void	get_sphere_uv(t_pnt *p, t_obj *obj, t_double2 *uv)
{
	t_vec tmp = mult(1 / obj->radius, sub(p->xyz, obj->pos));
	double phi = atan2(tmp.z, tmp.x);
	double theta = asin(tmp.y);
	uv->u = 1 - (phi + M_PI) / (2 * M_PI);
	uv->v = (theta + M_PI / 2) / M_PI;
}

t_double2	get_plane_texel(t_obj *obj, t_pnt *p)
{
	t_double2 uv = {0};
	t_vec u = compute_primary_tex_dir(nrm(obj->pos));
	t_vec v = cross_product(nrm(obj->pos), u);
	uv.u = dot(u, p->xyz);
	uv.v = dot(v, p->xyz);
	return uv;
}

t_double2	get_plane_texel1(t_obj *obj, t_pnt *p)
{
	t_double2 uv = {0};
	t_vec u = compute_primary_tex_dir(obj->pos);
	t_vec v = cross_product(obj->pos, u);
	uv.u = dot(u, sub(p->xyz, obj->pos));
	uv.v = dot(v, sub(p->xyz, obj->pos));
	return uv;
}

void 	get_plane_uv(t_pnt *p, t_obj *obj, t_double2 *uv)
{
	int k = 16;
	t_double2 uv1 = get_plane_texel1(obj, p);
	uv->u = fmod(uv1.u, k) / k;
	uv->v = fmod(uv1.v, k) / k;

	uv->u = fabs(uv->u);
	uv->v = fabs(uv->v);
}

void	get_uv(t_pnt *p, t_obj *obj, t_double2 *uv)
{
	if (obj->type == OBJECT_TYPE_PLANE)
		get_plane_uv(p, obj, uv);
	else if (obj->type == OBJECT_TYPE_SPHERE)
		get_sphere_uv(p, obj, uv);
	else if (obj->type == OBJECT_TYPE_CYLINDER)
		get_cylinder_uv(p, obj, uv);
}

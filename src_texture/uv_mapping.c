/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:26:09 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/24 22:13:31 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"



t_vec	get_texture_dir(t_vec d)
{
	t_vec a = cross_product(d, (t_vec){1, 0, 0});
	t_vec b = cross_product(d, (t_vec){0, 1, 0});

	t_vec max_ab = dot(a, a) < dot(b, b) ? b : a;

	t_vec c = cross_product(d, (t_vec){0, 0, 1});
	return nrm(dot(max_ab, max_ab) < dot(c, c) ? c : max_ab);
}

void	get_cyco_uv(t_pnt *p, t_obj *obj, t_double2 *uv)
{
	int k = 10;
//	t_vec tmp = mult(1 / obj->radius, sub(p->xyz, obj->pos));
	t_vec u = get_texture_dir(nrm(obj->dir));
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

	if (uv->v < 0)
		uv->v += 1;
//	uv->v = fmod(tmp2.y, (2.0 * M_PI) * k / (double )(2.0 * M_PI)) / k;
}

void	get_sphere_uv(t_pnt *p, t_obj *obj, t_double2 *uv)
{
	t_vec tmp = mult(1 / obj->radius, sub(p->xyz, obj->pos));
	//	TODO можно переворачивать текстур на объекте меняя местами z, x и у
//	TODO или можно менять знак у координат
	double phi = atan2(tmp.z, tmp.x);
	double theta = asin(tmp.y);
	uv->u = 1 - (phi + M_PI) / (2 * M_PI);
	uv->v = (theta + M_PI / 2) / M_PI;
}

//TODO Зачем нужна эта функция?
t_double2	get_plane_texel_g(t_obj *obj, t_pnt *p)
{
	t_double2 uv = {0};
	t_vec u = get_texture_dir(nrm(obj->pos));
	t_vec v = cross_product(nrm(obj->pos), u);
	uv.u = dot(u, p->xyz);
	uv.v = dot(v, p->xyz);
	return uv;
}

//TODO Зачем нужна эта функция?
t_double2	get_plane_texel_l(t_obj *obj, t_pnt *p)
{
	t_double2 uv = {0};
	t_vec u = get_texture_dir(nrm(obj->pos));
	t_vec v = cross_product(nrm(obj->pos), u);
	uv.u = dot(u, sub(p->xyz, obj->pos));
	uv.v = dot(v, sub(p->xyz, obj->pos));
	return uv;
}

void 	get_plane_uv(t_pnt *p, t_obj *obj, t_double2 *uv)
{
/*	int k = 10;
	t_double2 uv1 = get_plane_texel_l(obj, p);
	uv->u = fmod(uv1.u, k) / (double )k;
	uv->v = fmod(uv1.v, k) / (double )k;

	if (uv->u < 0)
		uv->u = 1 + uv->u;
	if (uv->v < 0)
		uv->v = 1 + uv->v;*/
	int k = 16;
//	TODO МОжно поворачивать текстуру меняя вектора
	t_vec e1 = nrm(cross_product(p->n, (t_vec){1,0, 0}));
	if (e1.x == 0 && e1.y == 0 && e1.z ==  0)
		e1 = nrm(cross_product(p->n, (t_vec){0, 0, 1}));

	t_vec e2 = nrm(cross_product(p->n, e1));
	uv->u = dot(e1, p->xyz);
	uv->v = dot(e2, p->xyz);

	uv->u = fmod(uv->u, k) / (double )k;
	uv->v = fmod(uv->v, k) / (double )k;

	if (uv->u < 0)
		uv->u = 1 + uv->u;
	if (uv->v < 0)
		uv->v = 1 + uv->v;


//	uv->u = fabs(uv->u);
//	uv->v = fabs(uv->v);
}

void	get_uv(t_pnt *p, t_obj *obj, t_double2 *uv)
{
	if (obj->type == OBJECT_TYPE_PLANE)
		get_plane_uv(p, obj, uv);
	else if (obj->type == OBJECT_TYPE_SPHERE)
		get_sphere_uv(p, obj, uv);
	else if (obj->type == OBJECT_TYPE_CYLINDER || obj->type == OBJECT_TYPE_CONE)
		get_cyco_uv(p, obj, uv);
}

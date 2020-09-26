/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:43 by mperseus          #+#    #+#             */
/*   Updated: 2020/09/26 17:26:01 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"


t_vec	cross_product(t_vec a, t_vec b)
{
	int i = a.y * b.z - a.z * b.y;
	int j = a.z * b.x - a.x * b.z;
	int k = a.x * b.y - a.y * b.x;
	return (t_vec){i, j , k};
}

t_clr	integer_to_rgb(int clr)
{
	return (t_clr){(clr >> 16) & 255, (clr >> 8) & 255, clr & 255};
}

void	trace_pixel(t_scene *scene, t_vec cam, t_pix *pix, int k)
{
	t_pnt	pnt;

	scene->obj = intersect(scene->objs, cam, pix->pos, (t_mn_mx){0, MIN, MAX});
	pix->depth = pix->depth == 0 ? scene->obj.closest : pix->depth;
	if (scene->obj.closest == MAX && pix->obj_id == EMPTY)
		pix->obj_id = NOTHING_SELECTED;
	if (scene->obj.closest == MAX)
		return ;
	if (pix->obj_id == EMPTY)
		pix->obj_id = scene->obj.id;
	pnt.xyz = add(cam, mult(scene->obj.closest, pix->pos));
	get_prop(scene, pix, &pnt, &scene->obj);
	if (k == 0 || (pnt.refl <= 0 && pnt.trns <= 0))
	{
		pix->color = pnt.final_clr;
		return ;
	}
	if (pnt.refl > 0)
	{
		pix->pos = reflect_ray(mult(-1.0, pix->pos), pnt.n);
		trace_pixel(scene, pnt.xyz, pix, k - 1);
		pix->color = add_color(multiply_color(1.0 - pnt.refl,
		pnt.final_clr), multiply_color(pnt.refl, pix->color));
	}
}

void	get_prop(t_scene *scene, t_pix *pix, t_pnt *pnt, t_obj *obj)
{
	pnt->color = scene->mats.arr[obj->mat]->color;
	if (obj->type == OBJECT_TYPE_PLANE)
		plane_n(pnt, pix->pos, obj);
	else if (obj->type == OBJECT_TYPE_SPHERE)
	{
		sphere_n(pnt, pix->pos, obj);
//		get_sphere_uv(mult(1 / obj->radius, sub(pnt->xyz, obj->pos)), &obj->u, &obj->v);
//		get_sphere_uv(pnt, obj, &obj->uv);
//		pnt->color = multiply_color(obj->v, pnt->color);
	}
	else if (obj->type == OBJECT_TYPE_CYLINDER)
		cylinder_n(pnt, pix->pos, obj, scene->cams.arr[scene->act_cam]->pos);
	else if (obj->type == OBJECT_TYPE_CONE)
		cone_n(pnt, pix->pos, obj, scene->cams.arr[scene->act_cam]->pos);
/*
	double scaleS = 5;
	double scaleT = 5;
	double pattern = (cos(pnt->n.y * 2 * M_PI * scaleT) * sin(pnt->n.x * 2 * M_PI * scaleS) + 1) * 0.5;
	pnt->color = multiply_color(pattern, scene->mats.arr[obj->mat]->color);
*/
//	Main func
//  pnt->color = scene->mats.arr[obj->mat]->color;
	get_uv(pnt, obj, &obj->uv);
	if (obj->pattern)
		pnt->color = integer_to_rgb(choose_pattern(pnt, obj, obj->uv));
	pnt->spec = scene->mats.arr[obj->mat]->spec;
	pnt->refl = scene->mats.arr[obj->mat]->refl;
	pnt->trns = scene->mats.arr[obj->mat]->transp;
	pnt->refr = scene->mats.arr[obj->mat]->refr;
	pnt->light = get_light(scene, *pnt, mult(-1.0, pix->pos));
/*	if (obj->t)
	{
		double phi = 0, theta = 0;
		double v = 0, u = 0;
//		t_vec norm = nrm(sub(obj->pos, pnt->xyz));
		t_vec norm = nrm(sub(pnt->xyz, obj->pos));
		t_vec pole = {0, 1, 0};
		t_vec equator = {1, 0, 0};
//		phi = acos(dot(pole, norm));
		phi = atan2(norm.x, norm.z);
		v = phi / PI;
		theta = (acos(dot(norm, equator))/ sin(phi)) / (2 * PI);
		if (dot(norm, cross_product(pole, equator)) > 0)
			u = theta;
		else
			u = 1 - theta / PI;

		if (u < 0)
			u = 0;
		if (v < 0)
			v = 0;
		if (u > 1.0)
			u = 1.0;
		if (v > 1.0)
			v = 1.0;

		int	height = 0;
		int	weight = 0;

		height = (int)(u * obj->t->t_h);
		weight = (int)(v * obj->t->t_w);
		int texel = height + weight * obj->t->size_line / 4;
		printf("%d\n", texel);
		if (texel < (obj->t->t_h * obj->t->t_w))
			pnt->color = integer_to_rgb(obj->t->addr[abs(texel)]);
	}*/
	pnt->final_clr = multiply_color(pnt->light, pnt->color);
}

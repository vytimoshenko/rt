/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:43 by mperseus          #+#    #+#             */
/*   Updated: 2020/10/17 18:32:05 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

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
	if (scene->mats.arr[obj->mat]->pattern || scene->mats.arr[obj->mat]->t)
		pnt->color = integer_to_rgb(identify_patt_tex(pnt, obj, obj->uv, scene->mats.arr[obj->mat]));
	pnt->spec = scene->mats.arr[obj->mat]->spec;
	pnt->refl = scene->mats.arr[obj->mat]->refl;
	pnt->trns = scene->mats.arr[obj->mat]->transp;
	pnt->refr = scene->mats.arr[obj->mat]->refr;
	pnt->light = get_light(scene, *pnt, mult(-1.0, pix->pos));
//	TODO выделить в отдельную функцию отрисовки картинки
/*
	if (obj->t)
	{
*/
/*
		double phi = 0, theta = 0;
		double v = 0, u = 0;
//		t_vec norm = nrm(sub(obj->pos, pnt->xyz));
		t_vec norm = nrm(sub(pnt->xyz, obj->pos));
		t_vec pole = {0, 1, 0};
		t_vec equator = {1, 0, 0};
		phi = acos(dot(pole, norm));
//		phi = atan2(norm.x, norm.z);
		v = phi / PI;
		theta = (acos(dot(norm, equator))/ sin(phi)) / (2 * PI);
		if (dot(norm, cross_product(pole, equator)) > 0)
			u = theta;
		else
			u = 1 - theta / PI;
*//*


		double u = obj->uv.u;
		double v = obj->uv.v;

		if (u < 0)
			u = 0;
		if (v < 0)
			v = 0;
		if (u > 1.0)
			u = 1.0;
		if (v > 1.0)
			v = 1.0;

		v = 1 - v;
		int 	height = 0;
		int 	weight = 0;

		height = (int )(v * (obj->t->t_h));
		weight = (int )(u * (obj->t->t_w));
		if (height >= obj->t->t_h)
			height = obj->t->t_h - 1;
		if (weight >= obj->t->t_w)
			weight = obj->t->t_w - 1;
//		int texel = height + weight * obj->t->size_line / 4;
		int texel = 4 +  height * obj->t->size_line / 4  + weight;
//		int *texel = obj->t->addr + height * obj->t->size_line / 4 + weight * obj->t->bits_per_pixel;
		printf("%d\n", texel);
		int c_scale = 1.0 / 255.0;
//		t_clr clr = {c_scale * texel[0], c_scale * texel[1], c_scale * texel[2]};
//		if (texel < (obj->t->t_h * obj->t->t_w))
//			pnt->color = integer_to_rgb(obj->t->addr[abs(texel)]);
		pnt->color = integer_to_rgb(obj->t->addr[texel]);
//		pnt->color = clr;
	}
*/
	pnt->final_clr = multiply_color(pnt->light, pnt->color);
}

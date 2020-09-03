/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:43 by mperseus          #+#    #+#             */
/*   Updated: 2020/09/03 18:44:11 by wquirrel         ###   ########.fr       */
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
	if (obj->type == OBJECT_TYPE_PLANE)
		plane_n(pnt, pix->pos, obj);
	else if (obj->type == OBJECT_TYPE_SPHERE)
		sphere_n(pnt, pix->pos, obj);
	else if (obj->type == OBJECT_TYPE_CYLINDER)
		cylinder_n(pnt, pix->pos, obj, scene->cams.arr[scene->act_cam]->pos);
	else if (obj->type == OBJECT_TYPE_CONE)
		cone_n(pnt, pix->pos, obj, scene->cams.arr[scene->act_cam]->pos);
	pnt->color = scene->mats.arr[obj->mat]->color;
	pnt->spec = scene->mats.arr[obj->mat]->spec;
	pnt->refl = scene->mats.arr[obj->mat]->refl;
	pnt->trns = scene->mats.arr[obj->mat]->transp;
	pnt->refr = scene->mats.arr[obj->mat]->refr;
	pnt->light = get_light(scene, *pnt, mult(-1.0, pix->pos));
/*	if (obj->t && obj->t->t_x <= 1)
	{
		int texel = (int)((double )obj->t->t_y * (obj->t->size_line * 4) + (double )obj->t->t_x * (obj->t->t_w * 4));
		pnt->color = integer_to_rgb(obj->t->addr[texel]);
		printf("y: %f; x: %f; = %d\n", obj->t->t_y, obj->t->t_x, texel);
		if ((int )(obj->t->t_x * 100) % 10 == 0 && obj->t->t_y <= 1)
			obj->t->t_y += 0.1f;
		obj->t->t_x += 0.001f;
	}*/
/*
	if (obj->t)
	{
		float k = 0.5f;
		int texel = obj->t->t_y  * obj->t->size_line / 4 + obj->t->t_x;
		pnt->color = integer_to_rgb(obj->t->addr[texel]);
		obj->t->t_x++;
		if (obj->t->t_x == obj->t->t_w)
		{
			obj->t->t_x = 0;
			if (obj->t->t_y <= obj->t->t_h)
				obj->t->t_y++;
		}
	}
*/
	if (obj->t)
	{
		double phi = 0, theta = 0;
		double v = 0, u = 0;
		t_vec norm = nrm(sub(obj->pos, pnt->xyz));
		t_vec pole = {0, 1, 0};
		t_vec equator = {1, 0, 0};
		phi = acos(dot(pole, norm));
		v = phi / PI;
		theta = (acos(dot(norm, equator))/ sin(phi)) / (2 * PI);
		if (dot(norm, cross_product(pole, equator)) > 0)
			u = theta;
		else
			u = 1 - theta;

		int	height = 0;
		int	weight = 0;

		height = (int)(u * obj->t->t_h);
		weight = (int)(v * obj->t->t_w);
		int texel = height + weight * obj->t->size_line / 4;
		printf("%d\n", texel);
		pnt->color = integer_to_rgb(obj->t->addr[texel]);
	}
	pnt->final_clr = multiply_color(pnt->light, pnt->color);
}

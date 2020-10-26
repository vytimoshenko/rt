/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:43 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:10:44 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	recursion(t_scene *scene, t_pnt pnt, t_pix *pix, t_obj obj, int k)
{
	if (pnt.refl > 0)
	{
		pix->pos = reflect_ray(mult(-1.0, pix->pos), pnt.n);
		trace_pixel(scene, pnt.xyz, pix, k - 1);
		pix->color = add_color(multiply_color(1.0 - pnt.refl,
		pnt.final_clr), multiply_color(pnt.refl, pix->color));
	}
	else if (pnt.refr > 0)
	{
		if (obj.t1 > 0.0001 && obj.t2 > 0.0001)
			pix->pos = refract_ray(mult(-1.0, pix->pos), pnt.n, 0);
		else
			pix->pos = refract_ray(mult(-1.0, pix->pos), pnt.n, 1);
		trace_pixel(scene, pnt.xyz, pix, k - 1);
		pix->color = add_color(pnt.final_clr, pix->color);
	}
	else if (pnt.trns > 0)
	{
		trace_pixel(scene, pnt.xyz, pix, k - 1);
		pix->color = add_color(pnt.final_clr, pix->color);
	}
}

void	trace_pixel(t_scene *scene, t_vec cam, t_pix *pix, int k)
{
	t_pnt	pnt;
	t_obj obj;

	obj = intersect(scene->objs, cam, pix->pos, (t_mn_mx){0, MIN, MAX});
	pix->depth = pix->depth == 0 ? obj.closest : pix->depth;
	if (obj.closest == MAX && pix->obj_id == EMPTY)
		pix->obj_id = NOTHING_SELECTED;
	if (obj.closest == MAX)
		return ;
	if (pix->obj_id == EMPTY)
		pix->obj_id = obj.id;
	pnt.xyz = add(cam, mult(obj.closest, pix->pos));
	get_prop(scene, pix, &pnt, &obj);
	if (k == 0 || (pnt.refl <= 0 && pnt.trns <= 0))
	{
		pix->color = pnt.final_clr;
		return ;
	}
	recursion(scene, pnt, pix, obj, k);
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
	pnt->trns = scene->mats.arr[obj->mat]->transp;
	pnt->refl = scene->mats.arr[obj->mat]->refl;
	pnt->refr = scene->mats.arr[obj->mat]->refr;
	if (obj->type == OBJECT_TYPE_PLANE)
		pnt->refr = 0;
	pnt->light = get_light(scene, *pnt, mult(-1.0, pix->pos));
	pnt->final_clr = multiply_color(pnt->light, pnt->color);
	if (pnt->refr > 0)
		pnt->final_clr = multiply_color(1.0 - pnt->refr, pnt->final_clr);
	else if (pnt->trns > 0)
		pnt->final_clr = multiply_color(1.0 - pnt->trns, pnt->final_clr);
}

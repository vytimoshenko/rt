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
	pnt->final_clr = multiply_color(pnt->light, pnt->color);
}

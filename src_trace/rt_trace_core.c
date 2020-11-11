/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:43 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/11 21:02:34 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	trace_pixel(t_scene *scene, t_vec cam, t_pix *pix, int k)
{
	t_pnt	pnt;
	t_obj	obj;

	obj = intersect(scene->objs, cam, pix->pos, (t_mn_mx){0, MIN, MAX});
	pix->depth = pix->depth == 0 ? obj.closest : pix->depth;
	if ((obj.closest == MAX && pix->obj_id == EMPTY) || obj.neg == 1)
		pix->obj_id = NOTHING_SELECTED;
	if (obj.closest == MAX)
		return ;
	if (pix->obj_id == EMPTY)
		pix->obj_id = obj.id;
	pnt.xyz = add(cam, mult(obj.closest, pix->pos));
	get_prop(scene, pix, &pnt, &obj);
	if (obj.neg == 1)
		return ;
	if (k == 0 || (pnt.refl <= 0 && pnt.refr <= 0 && pnt.trns <= 0))
	{
		pix->color = pnt.final_clr;
		return ;
	}
	obj.rec = k;
	recursion(scene, pnt, pix, obj);
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
	else if (obj->type == OBJECT_TYPE_PARABOLOID)
		paraboloid_n(pnt, pix->pos, obj, scene->cams.arr[scene->act_cam]->pos);
	else if (obj->type == OBJECT_TYPE_HYPERBOLOID)
		hyperboloid_n(pnt, pix->pos, obj, scene->cams.arr[scene->act_cam]->pos);
	pnt->color = scene->mats.arr[obj->mat]->color;
	get_uv(pnt, obj, &obj->uv, scene->mats.arr[obj->mat]);
	pnt->trns = scene->mats.arr[obj->mat]->transp;
	if (scene->mats.arr[obj->mat]->pattern || scene->mats.arr[obj->mat]->t)
		pnt->color = integer_to_rgb(
				identify_patt_tex(pnt, obj, obj->uv, scene->mats.arr[obj->mat],
								  &pnt->trns));
	pnt->spec = scene->mats.arr[obj->mat]->spec;
	pnt->refl = scene->mats.arr[obj->mat]->refl;
	pnt->refr = scene->mats.arr[obj->mat]->refr;
	pnt->angle = scene->mats.arr[obj->mat]->angle;
	pnt->refr = (obj->type == OBJECT_TYPE_PLANE) ? 0 : pnt->refr;
	pnt->light = get_light(scene, *pnt, mult(-1.0, pix->pos));
	pnt->final_clr = multiply_color(pnt->light, pnt->color);
	if (pnt->refr > 0)
		pnt->final_clr = multiply_color(1.0 - pnt->refr, pnt->final_clr);
	else if (pnt->trns > 0)
		pnt->final_clr = multiply_color(1.0 - pnt->trns, pnt->final_clr);
}

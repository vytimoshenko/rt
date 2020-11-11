/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_added.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:43 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/11 21:10:28 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

t_obj	check_planes(t_objs objs, t_obj plane, t_vec pix, t_vec cam)
{
	int		i;
	double	tmp;
	t_vec	vec;
	t_vec	point;

	i = -1;
	if (plane.type == OBJECT_TYPE_PLANE && plane.t1 > 0)
	{
		point = add(mult(plane.t1, pix), cam);
		while (++i < objs.quant)
		{
			if (objs.arr[i]->type == OBJECT_TYPE_PLANE
			&& objs.arr[i]->group == plane.group)
			{
				vec = nrm(sub(point, objs.arr[i]->pos));
				tmp = dot(objs.arr[i]->dir, vec);
				if (tmp >= MIN)
				{
					plane.t1 = -1;
					plane.t2 = -1;
				}
			}
		}
	}
	return (plane);
}

void	recursion(t_scene *scene, t_pnt pnt, t_pix *pix, t_obj obj)
{
	if (pnt.refl > 0)
	{
		pix->pos = reflect_ray(mult(-1.0, pix->pos), pnt.n);
		trace_pixel(scene, pnt.xyz, pix, obj.rec - 1);
		pix->color = add_color(multiply_color(1.0 - pnt.refl,
		pnt.final_clr), multiply_color(pnt.refl, pix->color));
	}
	else if (pnt.refr > 0)
	{
		if (obj.t1 > 0.0001 && obj.t2 > 0.0001)
			pix->pos = refract_ray(mult(-1.0, pix->pos), pnt.n, pnt.angle, 0);
		else
			pix->pos = refract_ray(mult(-1.0, pix->pos), pnt.n, pnt.angle, 1);
		trace_pixel(scene, pnt.xyz, pix, obj.rec - 1);
		pix->color = add_color(pnt.final_clr, pix->color);
	}
	else if (pnt.trns > 0)
	{
		trace_pixel(scene, pnt.xyz, pix, obj.rec - 1);
		pix->color = add_color(pnt.final_clr, pix->color);
	}
}

void	peaces(t_scene *scene)
{
	int		i;
	t_peace	peace[PEACES];

	i = -1;
	clean_pix_buffer(scene);
	prepare_pixs(scene);
	while (++i < PEACES)
	{
		peace[i].i = i;
		peace[i].scene = scene;
		pthread_create(&(peace[i].p), NULL, trace_rays, &(peace[i]));
	}
	i = -1;
	while (++i < PEACES)
		pthread_join(peace[i].p, NULL);
	fill_aliasing_buffer(scene);
}

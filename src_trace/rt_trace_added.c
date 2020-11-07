/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_added.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:43 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:10:44 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

t_obj	check_planes(t_objs objs, t_obj plane, t_vec pix, t_vec cam)
{
	int i;
	double tmp;
	t_vec vec;
	t_vec point;

	i = -1;	
	if (plane.type == OBJECT_TYPE_PLANE && plane.t1 > 0)
	{
		point = add(mult(plane.t1, pix), cam);
		while (++i < objs.quant)
		{
			if (objs.arr[i]->type == OBJECT_TYPE_PLANE)
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
		trace_pixel(scene, pnt.xyz, pix, obj.k - 1);
		pix->color = add_color(pnt.final_clr, pix->color);
	}
}

t_vec	refract_ray(t_vec r, t_vec n, double angl, int d)
{
	double c1;
	double c2;

	r = nrm(r);
	if (angl == 0)
		angl = 1 / 1.5;
	if (d == 1)
		angl = 1 / angl; 
	c1 = dot(r, n);
	c2 = sqrt(1.0 - (pow(angl, 2) * (1.0 - pow((c1), 2))));
	n = mult((angl * c1 - c2), n);
	r = mult(angl, r);
	return (sub(n, r));
}

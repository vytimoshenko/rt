/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_intersect_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:54 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:10:56 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	plane(t_obj *obj, t_vec cam, t_vec pix)
{
	double	t;
	t_vec	x;
	double	xdn;
	double	pdn;

	x = sub(cam, obj->pos);
	xdn = dot(x, obj->pos);
	pdn = dot(pix, obj->pos);
	if (!pdn)
	{
		obj->t1 = -1;
		obj->t2 = -1;
	}
	if ((t = -xdn / pdn) > 0)
	{
		obj->t1 = t;
		obj->t2 = t;
	}
	else
	{
		obj->t1 = -1;
		obj->t2 = -1;
	}
}

void	sphere(t_obj *obj, t_vec cam, t_vec pix)
{
	t_vec	r;
	double	k1;
	double	k2;
	double	k3;
	double	d;

	r = sub(cam, obj->pos);
	k1 = dot(pix, pix);
	k2 = 2.0 * dot(pix, r);
	k3 = dot(r, r) - obj->radius * obj->radius;
	d = k2 * k2 - 4.0 * k1 * k3;
	if (d < 0)
	{
		obj->t1 = -1;
		obj->t2 = -1;
		return ;
	}
	obj->t1 = (-k2 + sqrt(d)) / (2.0 * k1);
	obj->t2 = (-k2 - sqrt(d)) / (2.0 * k1);
}

void	cylinder(t_obj *obj, t_vec cam, t_vec pix)
{
	t_vec	r;
	double	k1;
	double	k2;
	double	k3;
	double	d;

	r = sub(cam, obj->pos);
	k1 = dot(pix, pix) - dot(pix, obj->dir) *
	dot(pix, obj->dir);
	k2 = 2.0 * (dot(pix, r) - dot(pix, obj->dir) *
	dot(r, obj->dir));
	k3 = dot(r, r) - dot(r, obj->dir) * dot(r, obj->dir) -
	obj->radius * obj->radius;
	d = k2 * k2 - 4 * k1 * k3;
	if (d < 0)
	{
		obj->t1 = -1;
		obj->t2 = -1;
		return ;
	}
	obj->t1 = (-k2 + sqrt(d)) / (2.0 * k1);
	obj->t2 = (-k2 - sqrt(d)) / (2.0 * k1);
}

void	cone(t_obj *obj, t_vec cam, t_vec pix)
{
	t_vec	r;
	double	k1;
	double	k2;
	double	k3;
	double	d;

	r = sub(cam, obj->pos);
	d = tan(deg_to_rad(obj->radius / 2.0));
	k1 = dot(pix, pix) - (1.0 + d * d) * dot(pix, obj->dir) *
	dot(pix, obj->dir);
	k2 = 2.0 * (dot(pix, r) - (1.0 + d * d) * dot(pix, obj->dir) *
	dot(r, obj->dir));
	k3 = dot(r, r) - (1 + d * d) * dot(r, obj->dir) * dot(r, obj->dir);
	d = k2 * k2 - 4.0 * k1 * k3;
	if (d < 0)
	{
		obj->t1 = -1;
		obj->t2 = -1;
		return ;
	}
	obj->t1 = (-k2 + sqrt(d)) / (2.0 * k1);
	obj->t2 = (-k2 - sqrt(d)) / (2.0 * k1);
}

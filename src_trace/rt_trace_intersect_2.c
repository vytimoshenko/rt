/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_intersect_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:54 by mperseus          #+#    #+#             */
/*   Updated: 2020/10/31 14:20:12 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

t_obj	plane(t_obj obj, t_vec cam, t_vec pix)
{
	double	t;
	t_vec	x;
	double	xdn;
	double	pdn;

	t = -1;
	x = sub(cam, obj.pos);
	xdn = dot(x, obj.dir);
	pdn = dot(pix, obj.dir);
	if (pdn)
	{
		t = -xdn / pdn;
		x = add(mult(t, pix), x);
	}
	if (t > 0 && (dot(x, x) < obj.radius * obj.radius || obj.radius == 0))
	{
		obj.t1 = t;
		obj.t2 = t;
	}
	else
	{
		obj.t1 = -1;
		obj.t2 = -1;
	}
	return (obj);
}

t_obj	sphere(t_obj obj, t_vec cam, t_vec pix)
{
	t_vec	r;
	double	k1;
	double	k2;
	double	k3;
	double	d;

	r = sub(cam, obj.pos);
	k1 = dot(pix, pix);
	k2 = 2.0 * dot(pix, r);
	k3 = dot(r, r) - obj.radius * obj.radius;
	d = k2 * k2 - 4.0 * k1 * k3;
	if (d < 0)
	{
		obj.t1 = -1;
		obj.t2 = -1;
		return (obj);
	}
	obj.t1 = (-k2 + sqrt(d)) / (2.0 * k1);
	obj.t2 = (-k2 - sqrt(d)) / (2.0 * k1);
	return (obj);
}

t_obj	cylinder(t_obj obj, t_vec cam, t_vec pix)
{
	t_vec	r;
	double	k1;
	double	k2;
	double	k3;
	double	d;

	r = sub(cam, obj.pos);
	k1 = dot(pix, pix) - dot(pix, obj.dir) * dot(pix, obj.dir);
	k2 = 2.0 * (dot(pix, r) - dot(pix, obj.dir) * dot(r, obj.dir));
	k3 = dot(r, r) - dot(r, obj.dir) * dot(r, obj.dir) -
	obj.radius * obj.radius;
	d = k2 * k2 - 4 * k1 * k3;
	if (d >= 0)
	{
		obj.t1 = (-k2 + sqrt(d)) / (2.0 * k1);
		obj.t2 = (-k2 - sqrt(d)) / (2.0 * k1);
		k1 = dot(r, obj.dir) + dot(mult(obj.t1, obj.dir), pix);
		k2 = dot(r, obj.dir) + dot(mult(obj.t2, obj.dir), pix);
		if ((k1 < obj.len && k1 > - obj.len) ||
		(k2 < obj.len && k2 > - obj.len) ||  obj.len == 0)
			return (obj);
	}
	obj.t1 = -1;
	obj.t2 = -1;
	return (obj);
}

t_obj	cone(t_obj obj, t_vec cam, t_vec pix)
{
	t_vec	r;
	double	k1;
	double	k2;
	double	k3;
	double	d;

	r = sub(cam, obj.pos);
	d = tan(deg_to_rad(obj.radius / 2.0));
	k1 = dot(pix, pix) - (1.0 + d * d) * dot(pix, obj.dir) *
	dot(pix, obj.dir);
	k2 = 2.0 * (dot(pix, r) - (1.0 + d * d) * dot(pix, obj.dir) *
	dot(r, obj.dir));
	k3 = dot(r, r) - (1 + d * d) * dot(r, obj.dir) * dot(r, obj.dir);
	d = k2 * k2 - 4.0 * k1 * k3;
	if (d >= 0)
	{
		obj.t1 = (-k2 + sqrt(d)) / (2.0 * k1);
		obj.t2 = (-k2 - sqrt(d)) / (2.0 * k1);
		k1 = dot(r, obj.dir) + dot(mult(obj.t1, obj.dir), pix);
		k2 = dot(r, obj.dir) + dot(mult(obj.t2, obj.dir), pix);
		if ((k1 < obj.len && k1 > 0) ||
		(k2 < obj.len && k2 > 0) || obj.len == 0)
			return (obj);
	}
	obj.t2 = -1;
	obj.t1 = -1;
	return (obj);
}

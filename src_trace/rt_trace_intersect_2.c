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

t_obj	plane(t_obj obj, t_vec cam, t_vec pix)
{
	t_vec	x;
	double	t;
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
	if ((t > 0 && dot(x, x) < obj.radius * obj.radius) || obj.radius == 0)
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
/*
t_obj	ellipsoid(t_obj obj, t_vec cam, t_vec pix)
{
	t_vec	x;
	double	k[3];
	double a[2];
	double d;
	double r2;

	x = sub(cam, obj.pos);
	r2 = obj.radius * obj.radius;
	a[0] = 2 * obj.len * dot(pix, obj.pos);
	a[1] = 2 * obj.len * dot(x, obj.pos) + r2 - obj.len * obj.len;
	k[0] = 4 * r2 * dot(pix, pix) - a[0] * a[0];
	k[1] = 4 * r2 * dot(pix, x) - a[0] * a[1];
	k[2] = 4 * r2 * dot(x, x) - a[1] * a[1];
	d = k[1] * k[1] - k[0] * k[2];
	if (d < 0)
	{
		obj.t1 = -1;
		obj.t2 = -1;
		return (obj);
	}
	obj.t1 = (-k[1] + sqrt(d)) / k[0];
	obj.t2 = (-k[1] - sqrt(d)) / k[0];
	return (obj);
}
*/
t_obj	paraboloid(t_obj obj, t_vec cam, t_vec pix)
{
	t_vec	x;
	double	k1;
	double	k2;
	double	k3;
	double	d;

	x = sub(cam, obj.pos);
	k1 = dot(pix, pix) - dot(pix, obj.dir) * dot(pix, obj.dir);
	k2 = dot(pix, x) - dot(pix, obj.dir) * (dot(x, obj.dir) + 2 * obj.radius);
	k3 = dot(x, x) - dot(x, obj.dir) * (dot(x, obj.dir) + 4 * obj.radius);
	d = k2 * k2 - k1 * k3;
	if (d >= 0)
	{
		obj.t1 = (-k2 + sqrt(d)) / k1;
		obj.t2 = (-k2 - sqrt(d)) / k1;
		k1 = dot(x, obj.dir) + dot(mult(obj.t1, obj.dir), pix);
		k2 = dot(x, obj.dir) + dot(mult(obj.t2, obj.dir), pix);
		if ((k1 < obj.len && k1 > - obj.len) ||
		(k2 < obj.len && k2 > - obj.len) ||  obj.len == 0)
			return (obj);
	}
	obj.t1 = -1;
	obj.t2 = -1;
	return (obj);
}

t_obj	hyperboloid(t_obj obj, t_vec cam, t_vec pix)
{
	t_vec	x;
	double	k1;
	double	k2;
	double	k3;
	double	d;

	x = sub(cam, obj.pos);
	k1 = pix.x * pix.x - pix.y * pix.y + pix.z * pix.z;
	k2 = x.x * pix.x - x.y * pix.y + x.z * pix.z;
	k3 = x.x * x.x - x.y * x.y + x.z * x.z - obj.radius * obj.radius;
	d = k2 * k2 - k1 * k3;
	if (d >= 0)
	{
		obj.t1 = (-k2 + sqrt(d)) / k1;
		obj.t2 = (-k2 - sqrt(d)) / k1;
		if (obj.t1 > 0 || obj.t2 > 0)
			return (obj);
	}
	obj.t1 = -1;
	obj.t2 = -1;
	return (obj);
}

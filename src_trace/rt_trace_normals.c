/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_normals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:11:11 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:11:13 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	plane_n(t_pnt *pnt, t_vec pix, t_obj *obj)
{
	pnt->n = dot(pix, obj->pos) < 0 ? obj->pos : mult(-1, obj->pos);
	pnt->n = nrm(pnt->n);
}

void	sphere_n(t_pnt *pnt, t_vec pix, t_obj *obj)
{
	t_vec	r;

	r = sub(pnt->xyz, obj->pos);
	pnt->n = dot(pix, r) < MIN ? r : mult(-1, r);
	pnt->n = nrm(pnt->n);
}

void	cylinder_n(t_pnt *pnt, t_vec pix, t_obj *obj, t_vec cam)
{
	double	m;
	t_vec	r;
	t_vec	p;

	r = sub(cam, obj->pos);
	m = obj->closest * dot(pix, obj->dir) + dot(r, obj->dir);
	p = add(cam, mult(obj->closest, pix));
	pnt->n = nrm(sub(sub(p, obj->pos), mult(m, obj->dir)));
	pnt->n = dot(pix, pnt->n) < MIN ? pnt->n : mult(-1, pnt->n);
}

void	cone_n(t_pnt *pnt, t_vec pix, t_obj *obj, t_vec cam)
{
	double	m;
	double	k;
	t_vec	r;

	r = sub(cam, obj->pos);
	m = obj->closest * dot(pix, obj->dir) + dot(r, obj->dir);
	k = obj->radius / m;
	pnt->n = nrm(sub(sub(pnt->xyz, obj->pos),
	mult(1.0 + k * k, mult(m, obj->dir))));
	pnt->n = dot(pix, pnt->n) < MIN ? pnt->n : mult(-1, pnt->n);
}

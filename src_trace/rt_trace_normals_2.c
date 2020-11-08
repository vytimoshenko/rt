/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_normals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:11:11 by mperseus          #+#    #+#             */
/*   Updated: 2020/10/31 14:20:12 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

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

void	paraboloid_n(t_pnt *pnt, t_vec pix, t_obj *obj, t_vec cam)
{
	double	m;
	t_vec	p;

	p = add(cam, mult(obj->closest, pix));
	m = dot(sub(p, obj->pos), obj->dir) * obj->radius;
	pnt->n = nrm(sub(sub(p, obj->pos), mult(m, obj->dir)));
	pnt->n = dot(pix, pnt->n) < MIN ? pnt->n : mult(-1, pnt->n);
}

void	hyperboloid_n(t_pnt *pnt, t_vec pix, t_obj *obj, t_vec cam)
{
	t_vec	p;

	p = add(cam, mult(obj->closest, pix));
	p = sub(p, obj->pos);
	pnt->n = nrm((t_vec){p.x, -p.y, p.z});
	pnt->n = dot(pix, pnt->n) < MIN ? pnt->n : mult(-1, pnt->n);
}

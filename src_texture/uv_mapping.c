/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:26:09 by wquirrel          #+#    #+#             */
/*   Updated: 2020/09/26 19:13:29 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

void	get_sphere_uv(t_pnt *p, t_obj *obj, t_uv *uv)
{
	t_vec tmp = mult(1 / obj->radius, sub(p->xyz, obj->pos));
	double phi = atan2(tmp.z, tmp.x);
	double theta = asin(tmp.y);
	uv->u = 1 - (phi + M_PI) / (2 * M_PI);
	uv->v = (theta + M_PI / 2) / M_PI;
}

void 	get_plane_uv(t_pnt *p, t_uv *uv)
{
	int k = 32;
	uv->u = fmod(p->xyz.x, k) / k;
	uv->v = fmod(p->xyz.z, k) / k;
}

void	get_uv(t_pnt *p, t_obj *obj, t_uv *uv)
{
	if (obj->type == OBJECT_TYPE_PLANE)
		get_plane_uv(p, uv);
	else if (obj->type == OBJECT_TYPE_SPHERE)
		get_sphere_uv(p, obj, uv);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:50:46 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/28 21:08:22 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

t_vec		get_texture_dir(t_vec d)
{
	if (d.x != 0 && d.y != 0)
		return (t_vec) {-d.y, d.x, 0.0};
	else if (d.x == 0)
		return (t_vec){1, 0, 0};
	else if (d.y == 0)
		return (t_vec){0, 1, 0};
	else
		return (t_vec){0, 0, 1};
}

t_double2	get_plane_texel_g(t_obj *obj, t_pnt *p)
{
	t_double2	uv;
	t_vec		u;
	t_vec		v;

	u = get_texture_dir(nrm(obj->pos));
	v = cross_product(nrm(obj->pos), u);
	uv.u = dot(u, p->xyz);
	uv.v = dot(v, p->xyz);
	return (uv);
}

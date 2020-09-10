/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_procedural.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:48:06 by wquirrel          #+#    #+#             */
/*   Updated: 2020/09/10 16:31:33 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

int		stripe_pattern(t_pnt *pnt, t_obj *obj)
{
	double xyz;

	xyz = obj->pattern == 1 ? pnt->n.x : obj->pattern == 2 ? pnt->n.y
														   : pnt->n.z;
	if (obj->type != OBJECT_TYPE_PLANE)
		xyz *= obj->radius;
	else
	{
		t_vec n_xyz = sub(pnt->xyz, obj->pos);
		xyz += obj->pattern == 1 ? n_xyz.x : obj->pattern == 2 ? n_xyz.y
																  : n_xyz.z;
	}

	if ((int )floor(xyz) % 2 == 0)
		return T_COLOR_W;
	else
		return T_COLOR_BL;
}

int		choose_pattern(t_pnt *pnt, t_obj *obj)
{
	if (obj->pattern >= STRIPE_X && obj->pattern <= STRIPE_Z)
		return stripe_pattern(pnt, obj);
	return (0);
}
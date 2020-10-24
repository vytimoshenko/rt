/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_intersect_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:49 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:10:50 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

t_obj	select_obj_intersect(t_obj obj, t_vec cam, t_vec pix)
{
	t_obj result;

	if (obj.type == OBJECT_TYPE_PLANE)
		result = plane(obj, cam, pix);
	else if (obj.type == OBJECT_TYPE_SPHERE)
		result = sphere(obj, cam, pix);
	else if (obj.type == OBJECT_TYPE_CYLINDER)
		result = cylinder(obj, cam, pix);
	else if (obj.type == OBJECT_TYPE_CONE)
		result = cone(obj, cam, pix);
	return (result);
}

t_obj	intersect(t_objs objs, t_vec cam, t_vec pix, t_mn_mx t_min_max)
{
	int		i;
	t_obj	closest_obj;
	t_obj	tmp;

	i = -1;
	t_min_max.t = t_min_max.t_max;
	closest_obj.null = 0;
	while (++i < objs.quant)
	{
		tmp = select_obj_intersect(*objs.arr[i], cam, pix);
		if (tmp.t1 >= t_min_max.t_min && tmp.t1 <=
		t_min_max.t_max && tmp.t1 < t_min_max.t)
		{
			t_min_max.t = tmp.t1;
			closest_obj = tmp;
			closest_obj.null = 1;
		}
		if (tmp.t2 >= t_min_max.t_min && tmp.t2 <=
		t_min_max.t_max && tmp.t2 < t_min_max.t)
		{
			t_min_max.t = tmp.t2;
			closest_obj = tmp;
			closest_obj.null = 1;
		}
	}
	return (check_closest_obj(closest_obj, t_min_max.t));
}

t_obj	check_closest_obj(t_obj closest_obj, double t)
{
	closest_obj.closest = t;
	if (closest_obj.null == 1)
		closest_obj.null = 1;
	else
		closest_obj.null = 0;
	return (closest_obj);
}

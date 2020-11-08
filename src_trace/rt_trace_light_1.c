/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:11:00 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:11:02 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

double	get_light(t_scene *scene, t_pnt pnt, t_vec pix)
{
	int		i;
	double	tmp;
	double	intensity;

	intensity = 0;
	i = -1;
	while (++i < scene->lights.quant)
	{
		if (scene->lights.arr[i]->off == FALSE)
		{
			if (scene->lights.arr[i]->type == LIGHT_TYPE_AMBIENT)
				intensity += scene->lights.arr[i]->intens;
			else if ((tmp = diffuse_and_specular(scene, pnt, pix, i))
			!= -1)
				intensity += tmp;
		}
	}
	return (intensity);
}

double	shadow(t_scene *scene, t_pnt pnt, t_vec l, double t_max)
{
	t_obj	sh;
	double	ret;
	double	t;

	sh = nearest_obj(scene->objs, pnt.xyz, l,
	(t_mn_mx){0, 0.000001, t_max});
	if (sh.null && scene->mats.arr[sh.mat]->transp == 0.0 && sh.neg == 0)
		ret = 0;
	else
	{
		ret = 1;
		while (sh.null && scene->mats.arr[sh.mat]->transp > 0)
		{
			if (sh.neg == 0)
				ret *= scene->mats.arr[sh.mat]->transp;
			t = (sh.t1 > sh.t2) ? sh.t1 : sh.t2;
			pnt.xyz = add(pnt.xyz, mult(t, l));
			sh = nearest_obj(scene->objs, pnt.xyz, l,
			(t_mn_mx){0, 0.000001, t_max});
		}
	}
	return (ret);
}

double	diffuse_and_specular(t_scene *scene, t_pnt pnt,
			t_vec pix, int i)
{
	t_vec	l;
	t_obj	sh;
	double	t_max;
	double	intensity;

	if (scene->lights.arr[i]->type == LIGHT_TYPE_POINT)
	{
		l = sub(scene->lights.arr[i]->pos, pnt.xyz);
		t_max = 1;
	}
	else
	{
		l = scene->lights.arr[i]->pos;
		t_max = MAX;
	}
	sh = intersect(scene->objs, pnt.xyz, l,
	(t_mn_mx){0, 0.000001, t_max});
	if (sh.null && scene->mats.arr[sh.mat]->transp == 0.0)
		return (-1);
	intensity = scene->lights.arr[i]->intens * diffuse(pnt.n, l);
	if (pnt.spec)
		intensity += scene->lights.arr[i]->intens *
		specular(pnt.n, l, pix, pnt.spec);
	return (intensity * shadow(scene, pnt, l, t_max));
}

double	diffuse(t_vec n, t_vec l)
{
	double	ndl;

	ndl = dot(n, l);
	if (ndl > 0)
		return (ndl / (len(n) * len(l)));
	else
		return (0);
}

double	specular(t_vec n, t_vec l, t_vec p, double s)
{
	t_vec	r;
	double	rdp;

	r = reflect_ray(l, n);
	rdp = dot(r, p);
	if (rdp > 0)
		return (pow(rdp / (len(r) * len(p)), s));
	else
		return (0);
}

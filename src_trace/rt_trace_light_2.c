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

t_vec	refract_ray(t_vec r, t_vec n, double angl, int d)
{
	double c1;
	double c2;

	r = nrm(r);
	if (angl == 0)
		angl = 1 / 1.5;
	if (d == 1)
		angl = 1 / angl;
	c1 = dot(r, n);
	c2 = sqrt(1.0 - (pow(angl, 2) * (1.0 - pow((c1), 2))));
	n = mult((angl * c1 - c2), n);
	r = mult(angl, r);
	return (sub(n, r));
}

t_vec	reflect_ray(t_vec r, t_vec n)
{
	return (sub(mult(2.0 * dot(r, n), n), r));
}

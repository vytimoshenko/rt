/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_vector_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:11:17 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:11:19 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

double	deg_to_rad(int degrees)
{
	return ((double)degrees * PI / 180.0);
}

double	dot(t_vec v1, t_vec v2)
{
	return ((double)(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z));
}

double	len(t_vec v)
{
	return ((double)sqrt(dot(v, v)));
}

t_vec	nrm(t_vec v)
{
	return ((mult(1.0 / len(v), v)));
}

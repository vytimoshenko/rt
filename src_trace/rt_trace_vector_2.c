/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_vector_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:11:23 by mperseus          #+#    #+#             */
/*   Updated: 2020/10/31 14:20:12 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

t_vec	add(t_vec v1, t_vec v2)
{
	t_vec result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vec	sub(t_vec v1, t_vec v2)
{
	t_vec result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

t_vec	mult(double k, t_vec v)
{
	t_vec result;

	result.x = k * v.x;
	result.y = k * v.y;
	result.z = k * v.z;
	return (result);
}

t_vec	cross_product(t_vec a, t_vec b)
{
	double i = a.y * b.z - a.z * b.y;
	double j = a.z * b.x - a.x * b.z;
	double k = a.x * b.y - a.y * b.x;
	return (t_vec){i, j , k};
}
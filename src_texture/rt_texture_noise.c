/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_texture_noises.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:57:16 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/28 22:25:08 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

int		p_perm(char *act, int i, int val)
{
	static int perm[256] = {0};

	if (ft_strequ(act, "get"))
		return (perm[i]);
	else if (ft_strequ(act, "set"))
		perm[i] = val;
	return (0);
}

double	p_grads_xy(char v, char *act, int i, double val)
{
	static double	grads_x[256] = {0};
	static double	grads_y[256] = {0};
	double			*grads;

	grads = ft_strchr("x", v) > 0 ? grads_x : grads_y;
	if (ft_strequ(act, "get"))
		return (grads[i]);
	else if (ft_strequ(act, "set"))
		grads[i] = val;
	return (0);
}

void	init_noise(void)
{
	int i;
	int other;

	i = 0;
	while (i < P_SIZE)
	{
		other = rand() % (i + 1);
		if (i > other)
			p_perm("set", i, p_perm("get", other, 0));
		p_perm("set", other, i);
		p_grads_xy('x', "set", i, cos(2.0 * M_PI * i / 256));
		p_grads_xy('y', "set", i, sin(2.0 * M_PI * i / 256));
		i++;
	}
}

double	noise(t_double2 uv, double	result)
{
	int		cell_x;
	int		cell_y;

	result = 0.0f;
	cell_x = floor(uv.u);
	cell_y = floor(uv.v);
	for (int grid_y = cell_y; grid_y  <= cell_y + 1; grid_y++)
	{
		for (int grid_x = cell_x; grid_x <= cell_x + 1; grid_x++)
		{
			int hash = p_perm("get", (p_perm(
					"get", grid_x & 255, 0) + grid_y) & 255, 0);
			result += surflet(
					(t_double2){uv.u - grid_x, uv.v - grid_y}
					, p_grads_xy('x', "get", hash, 0)
					, p_grads_xy('y', "get", hash, 0));
		}
	}
	return result;
}

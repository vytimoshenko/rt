/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_perline_noise.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:36:12 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/24 21:09:04 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "rt.h"

# define NOISE_WIDTH 128
# define NOISE_HEIGHT 128

int		p_perm(char *act, int i, int val)
{
	static int perm[256] = {0};

	if (ft_strequ(act, "get"))
		return perm[i];
	else if (ft_strequ(act, "set"))
		perm[i] = val;
	return (0);
}

double 		p_grads_xy(char v, char *act, int i, double val)
{
	static double grads_x[256] = {0};
	static double grads_y[256] = {0};
	double *grads;

	grads = ft_strchr("x", v) > 0 ? grads_x : grads_y;
	if (ft_strequ(act, "get"))
		return grads[i];
	else if (ft_strequ(act, "set"))
		grads[i] = val;
	return (0);
}


void init_p()
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

/*void init()
{
	for (int i = 0; i < size; ++i)
	{
		int other = rand() % (i + 1);
		if (i > other)
			perm[i] = perm[other];
		perm[other] = i;
		grads_x[i] = cos(2.0 * M_PI * i / size);
		grads_y[i] = sin(2.0 * M_PI * i / size);
	}
}*/

double f(double t)
{
	t = fabs(t);
	return t >= 1.0f ? 0.0f : 1.0f - (3.0f - 2.0 * t ) * t * t;
}

double surflet(t_double2 uv, double grad_x, double grad_y)
{
	return f(uv.u) * f(uv.v) * (grad_x * uv.u + grad_y * uv.v);
}

double noise(t_double2 uv)
{
	double result = 0.0f;
	int cell_x = floor(uv.u);
	int cell_y = floor(uv.v);
	for (int grid_y = cell_y; grid_y  <= cell_y + 1; grid_y++)
	{
		for (int grid_x = cell_x; grid_x <= cell_x + 1; grid_x++)
		{
//			int hash = perm[(perm[grid_x & mask] + grid_y) & mask];
			int hash = p_perm("get", (p_perm("get", grid_x & 255, 0) + grid_y) & 255, 0);
//			result += surflet((t_double2){uv.u - grid_x, uv.v - grid_y}, grads_x[hash], grads_y[hash]);
			result += surflet((t_double2){uv.u - grid_x, uv.v - grid_y}
			, p_grads_xy('x', "get", hash, 0), p_grads_xy('y', "get", hash, 0));
		}
	}
	return result;
}

int perlin_noise(t_obj *obj)
{
	double n;
	n = noise((t_double2){obj->uv.u * 100, obj->uv.v * 100});
	n = 0.5 * (n + 1.0);
	return rgb_to_integer((t_clr){
		255 * n,
		255 * n,
		255 * n});
}


int wood(t_obj *obj)
{
	double n;
	double period = 10;
	n =  noise((t_double2){obj->uv.u * 10, obj->uv.v * 5});
//	n = n - floor(n);
//	n = 0.5 * (n + 1.0);
	double sine = 128.0 * fabs(sin(2 * period * n * M_PI));
	t_clr clr = {
			80 + sine,
			30 + sine,
			30
	};
//	t_double2 uv = {obj->uv.u * obj->uv.u * n, obj->uv.v * obj->uv.v * n};
//	int clr = stripe_pattern(obj, obj->uv, mat);

	return rgb_to_integer((t_clr){clr.r, clr.g, clr.b});
//	return stripe_pattern(obj, uv, mat);
}

int		marble(t_obj *obj)
{
	double n;
	n =  noise((t_double2){obj->uv.u * 16, obj->uv.v * 32});
//	n = n - floor(n);
//	n = 0.5 * (n + 1.0);
	double sine = 256.0 * fabs(sin(n * M_PI));
	t_clr clr = {
			sine,
			sine,
			sine
	};
//	t_double2 uv = {obj->uv.u * obj->uv.u * n, obj->uv.v * obj->uv.v * n};
//	int clr = stripe_pattern(obj, obj->uv, mat);

	return rgb_to_integer((t_clr){clr.r, clr.g, clr.b});
//	return stripe_pattern(obj, uv, mat);
}
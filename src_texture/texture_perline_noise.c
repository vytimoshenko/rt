/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_perline_noise.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:36:12 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/23 20:49:24 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "rt.h"

# define NOISE_WIDTH 128
# define NOISE_HEIGHT 128

int const size = 256;
int const mask = size - 1;
int perm[size];
double grads_x[size];
double grads_y[size];

void init_p(t_perlin *p)
{
	int i;
	int other;

	i = 0;
	p->perm = (int *)malloc(sizeof(int) * P_SIZE);
	p->grads_y = (double *)malloc(sizeof(int) * P_SIZE);
	p->grads_x = (double *)malloc(sizeof(int) * P_SIZE);
	while (i < P_SIZE)
	{
		other = rand() % (i + 1);
		if (i > other)
			p->perm[i] = perm[other];
		p->perm[other] = i;
		p->grads_x[i] = cos(2.0 * M_PI * i / size);
		p->grads_y[i] = sin(2.0 * M_PI * i / size);
		i++;
	}
}

void init()
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
}

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
			int hash = perm[(perm[grid_x & mask] + grid_y) & mask];
			result += surflet((t_double2){uv.u - grid_x, uv.v - grid_y}, grads_x[hash], grads_y[hash]);
		}
	}
	return result;
}

int perlin_noise(t_obj *obj)
{
	double n;
	n = noise((t_double2){obj->uv.u * 100, obj->uv.v * 100});
	n = 0.5 * (n + 1.0);
	return rgb_to_integer((t_clr){255 * n, 255 * n, 255 * n});
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_effect_antialias_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:06:35 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:06:36 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	run_antialiasing(t_scene *scene)
{
	int			i;
	double		jitter[MULTI_SAMPLING_RATE];
	t_pix		pix;

	get_jitter(jitter);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		if (scene->pix_buff[i].aliasing)
		{
			pix.x = scene->pix_buff[i].x;
			pix.y = scene->pix_buff[i].y;
			get_multisample_color(scene, &pix, jitter);
			scene->pix_buff[i].color = pix.color;
		}
	}
}

void	get_jitter(double *random)
{
	int i;

	srand(42);
	i = -1;
	while (++i < MULTI_SAMPLING_RATE)
	{
		random[i] = (rand() % 100 + 1.0) / 5000.0;
		if (i % 2)
			random[i] *= -1;
	}
}

void	get_multisample_color(t_scene *scene, t_pix *pix, double *jitter)
{
	int		i;
	t_vec	sum;
	t_vec	tmp;

	sum = (t_vec){0, 0, 0};
	i = -1;
	tmp.z = scene->cams.arr[scene->act_cam]->pos.z;
	while (++i < MULTI_SAMPLING_RATE)
	{
		tmp.x = 0;
		tmp.y = 0;
		pix->color = (t_clr){0, 0, 0};
		get_pix_viewport_coordinates(scene, pix);
		tmp.x = jitter[i] + scene->cams.arr[scene->act_cam]->
		pos.x;
		tmp.y = jitter[i] + scene->cams.arr[scene->act_cam]->
		pos.y;
		trace_pixel(scene, tmp, pix, REFLECTION_DEPTH);
		sum.x += pix->color.r;
		sum.y += pix->color.g;
		sum.z += pix->color.b;
	}
	pix->color.r = (sum.x / (MULTI_SAMPLING_RATE));
	pix->color.g = (sum.y / (MULTI_SAMPLING_RATE));
	pix->color.b = (sum.z / (MULTI_SAMPLING_RATE));
}

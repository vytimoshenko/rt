/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:11:06 by mperseus          #+#    #+#             */
/*   Updated: 2020/10/31 14:20:12 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	peaces(t_scene *scene)
{
	int i;
	t_peace peace[PEACES];

	i = -1;
	clean_pix_buffer(scene);
	prepare_pixs(scene);
	while (++i < PEACES)
	{
		peace[i].i = i;
		peace[i].scene = scene;
		pthread_create(&(peace[i].p), NULL, trace_rays, &(peace[i]));
	}
	i = -1;
	while (++i < PEACES)
		pthread_join(peace[i].p, NULL);
	fill_aliasing_buffer(scene);
}

void	*trace_rays(void *peace)
{
	int	i;
	t_peace *p;

	p = (t_peace *)peace;
	i = IMG_SIZE_W * IMG_SIZE_H / PEACES * p->i - 1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H / PEACES * (p->i + 1))
		trace_pixel(p->scene, p->scene->cams.arr[p->scene->act_cam]->
		pos, &p->scene->pix_buff[i], REFLECTION_DEPTH);
	return (0);
}

void	prepare_pixs(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		scene->pix_buff[i].i = i;
		get_centered_coordinates(&scene->pix_buff[i]);
		get_pix_viewport_coordinates(scene, &scene->pix_buff[i]);
	}
}

void	get_centered_coordinates(t_pix *pix)
{
	pix->x = pix->i % (int)IMG_SIZE_W - 0.5 * (int)IMG_SIZE_W;
	pix->y = 0.5 * (int)IMG_SIZE_H - pix->i / (int)IMG_SIZE_W;
}

void	get_pix_viewport_coordinates(t_scene *scene, t_pix *pix)
{
	pix->pos.x = pix->x * VIEWPORT_SIZE_W / IMG_SIZE_W;
	pix->pos.y = pix->y * VIEWPORT_SIZE_H / IMG_SIZE_H;
	pix->pos.z = VIEWPORT_DISTANCE;
	rotate_pix(pix, scene->cams.arr[scene->act_cam]);
}

void	rotate_pix(t_pix *pix, t_cam *cam)
{
	double temp1;
	double temp2;

	temp1 = pix->pos.y * cam->cos.x + pix->pos.z * cam->sin.x;
	temp2 = -pix->pos.y * cam->sin.x + pix->pos.z * cam->cos.x;
	pix->pos.y = temp1;
	pix->pos.z = temp2;
	temp1 = pix->pos.x * cam->cos.y + pix->pos.z * cam->sin.y;
	temp2 = -pix->pos.x * cam->sin.y + pix->pos.z * cam->cos.y;
	pix->pos.x = temp1;
	pix->pos.z = temp2;
	temp1 = pix->pos.x * cam->cos.z - pix->pos.y * cam->sin.z;
	temp2 = pix->pos.x * cam->sin.z + pix->pos.y * cam->cos.z;
	pix->pos.x = temp1;
	pix->pos.y = temp2;
}

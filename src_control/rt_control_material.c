/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control_material.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:06:06 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:06:08 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	change_material(t_scene *scene, int key)
{
	if (key == MORE && scene->act_mat != scene->mats.quant - 1)
		scene->act_mat++;
	else if (key == MORE && scene->act_mat ==
	scene->mats.quant - 1)
		scene->act_mat = 0;
	else if (key == LESS && scene->act_mat != 0)
		scene->act_mat--;
	else if (key == LESS && scene->act_mat == 0)
		scene->act_mat = scene->mats.quant - 1;
}

void	get_material(int x, int y, t_global *global)
{
	int	i;

	if (global->scene->act_mod == MODE_MATERIAL && x >= WIN_SIZE_W - 200 &&
	x < WIN_SIZE_W - 182 && y >= 283 && y < 301)
	{
		global->scene->mat_source = global->scene->act_mat;
		return ;
	}
	x = x - IMG_INDT_W;
	y = y - IMG_INDT_H;
	if (x < 0 || x > IMG_SIZE_W || y < 0 || y > IMG_SIZE_H)
		return ;
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	if (global->scene->pix_buff[i].obj_id == NOTHING_SELECTED)
		return ;
	global->scene->mat_source =
	global->scene->objs.arr[global->scene->pix_buff[i].obj_id]->mat;
}

int		apply_material(int x, int y, t_global *global)
{
	int	i;

	x = x - IMG_INDT_W;
	y = y - IMG_INDT_H;
	if (x < 0 || x > IMG_SIZE_W || y < 0 || y > IMG_SIZE_H)
	{
		global->scene->mat_source = NOTHING_SELECTED;
		return (0);
	}
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	if (global->scene->pix_buff[i].obj_id == -1 || global->scene->
	objs.arr[global->scene->pix_buff[i].obj_id]->mat ==
	global->scene->mat_source)
	{
		global->scene->mat_source = NOTHING_SELECTED;
		return (0);
	}
	global->scene->objs.arr[global->scene->pix_buff[i].obj_id]->
	mat = global->scene->mat_source;
	global->scene->mat_source = NOTHING_SELECTED;
	return (1);
}

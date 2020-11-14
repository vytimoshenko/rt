/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control_material.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:06:06 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/14 16:20:57 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/rt.h"

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

	if (global->scene->act_mod == MODE_MATERIAL && x >= WIN_SIZE_W - 227 &&
	x < WIN_SIZE_W - 209 && y >= 237 && y < 255)
	{
		global->scene->mat_source = global->scene->act_mat;
		return ;
	}
	if (global->scene->act_mod == MODE_OBJECT && x >= WIN_SIZE_W - 227 &&
	x < WIN_SIZE_W - 209 && y >= 337 && y < 355)
	{
		global->scene->mat_source =
		global->scene->objs.arr[global->scene->act_obj]->mat;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:06:13 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/12 19:53:00 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

int		select_object(int x, int y, t_global *global)
{
	int	i;
	int object_id;

	x = x - IMG_INDT_W;
	y = y - IMG_INDT_H;
	if (x < 0 || x > IMG_SIZE_W || y < 0 || y > IMG_SIZE_H)
		return (-1);
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	object_id = global->scene->pix_buff[i].obj_id;
	if (object_id == NOTHING_SELECTED)
	{
		global->scene->act_mod = MODE_CAMERA;
		global->scene->act_obj = NOTHING_SELECTED;
		return (1);
	}
	global->scene->act_mod = MODE_OBJECT;
	if (global->scene->act_obj == object_id)
		return (0);
	else
	{
		global->scene->act_obj = object_id;
		return (1);
	}
}

void	change_object(t_scene *scene, int key)
{
	if (key == MORE && scene->act_obj != scene->objs.quant - 1)
		scene->act_obj++;
	else if (key == MORE && scene->act_obj == scene->objs.quant - 1)
		scene->act_obj = 0;
	else if (key == LESS && scene->act_obj != 0)
		scene->act_obj--;
	else if (key == LESS && scene->act_obj == 0)
		scene->act_obj = scene->objs.quant - 1;
}

void	move_object(t_global *global, int key)
{
	int i;
	int group;

	i = global->scene->act_obj;
	if (global->scene->objs.arr[i]->group != NO_GROUP)
	{
		group = global->scene->objs.arr[i]->group;
		i = -1;
		while (++i < global->scene->objs.quant)
		{
			if (global->scene->objs.arr[i]->group == group)
				make_move(global, key, i);
		}
	}
	else
		make_move(global, key, i);
}

void	make_move(t_global *global, int key, int i)
{
	int	mov;

	if (global->scene->ready_for_motion == true)
	{
		global->scene->move_direction = key;
		update_interface_only(global);
		make_motion_blur(global);
		global->scene->move_direction = 0;
	}
	if (global->scene->in_motion == true)
		mov = OBJECT_MOVEMENT_INCREMENT / MOTION_BLUR_BUFFERS;
	else
		mov = OBJECT_MOVEMENT_INCREMENT;
	if (key == ARROW_DOWN)
		global->scene->objs.arr[i]->pos.y -= mov;
	else if (key == ARROW_UP)
		global->scene->objs.arr[i]->pos.y += mov;
	else if (key == ARROW_RIGHT)
		global->scene->objs.arr[i]->pos.x += mov;
	else if (key == ARROW_LEFT)
		global->scene->objs.arr[i]->pos.x -= mov;
	else if (key == BRACKET_RIGHT)
		global->scene->objs.arr[i]->pos.z += mov;
	else if (key == BRACKET_LEFT)
		global->scene->objs.arr[i]->pos.z -= mov;
}

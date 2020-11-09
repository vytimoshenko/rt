/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control_keyboard_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:05:40 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/09 19:50:12 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	escape_key(t_global *global, int key)
{
	if (key == ESC)
	{
		global->scene->show_help = FALSE;
		global->scene->show_info = FALSE;
		global->scene->got_color = FALSE;
		global->scene->ready_for_motion = FALSE;
		if (global->scene->finished_motion == true &&
		global->scene->act_mod == MODE_CAMERA)
		{
			global->scene->finished_motion = false;
			show_last_frame(global->scene);
			update_interface_and_frame(global);
		}
		if (global->scene->act_mod == MODE_OBJECT ||
		global->scene->act_mod == MODE_EFFECT)
		{
			global->scene->act_mod = MODE_CAMERA;
			update_interface_and_frame(global);
		}
		else
		{
			global->scene->act_mod = MODE_CAMERA;
			update_interface_only(global);
		}
	}
}

void	change_mode_1(t_global *global, int key)
{
	if (key == L || key == M)
	{
		if (key == L && global->scene->act_mod != MODE_LIGHT)
		{
			global->scene->act_mod = MODE_LIGHT;
			update_interface_and_frame(global);
		}
		else if (key == L && global->scene->act_mod == MODE_LIGHT)
			global->scene->act_mod = MODE_CAMERA;
		else if (key == M && global->scene->act_mod != MODE_MATERIAL)
		{
			if (global->scene->act_mod == MODE_OBJECT)
			{
				global->scene->act_mod = MODE_MATERIAL;
				update_interface_and_frame(global);
				return ;
			}
			global->scene->act_mod = MODE_MATERIAL;
		}
		else if (key == M && global->scene->act_mod == MODE_MATERIAL)
			global->scene->act_mod = MODE_CAMERA;
		update_interface_only(global);
	}
}

void	change_mode_2(t_global *global, int key)
{
	if (key == O || key == E)
	{
		if (key == O && global->scene->act_mod != MODE_OBJECT)
			global->scene->act_mod = MODE_OBJECT;
		else if (key == O && global->scene->act_mod == MODE_OBJECT)
			global->scene->act_mod = MODE_CAMERA;
		else if (key == E && global->scene->act_mod != MODE_EFFECT)
			global->scene->act_mod = MODE_EFFECT;
		else if (key == E && global->scene->act_mod == MODE_EFFECT)
			global->scene->act_mod = MODE_CAMERA;
		update_interface_and_frame(global);
	}
	if (key == B)
	{
		global->scene->act_mod = MODE_OBJECT;
		info_message_box(global->mlx, MOTION_BLUR_TITLE,
		"For motion blur select object and move it");
		global->scene->ready_for_motion = true;
	}
}

void	change_item(t_global *global, int key)
{
	if (key == LESS || key == MORE)
	{
		if (global->scene->act_mod == MODE_CAMERA)
		{
			change_camera(global->scene, key);
			draw(global);
			return ;
		}
		else if (global->scene->act_mod == MODE_LIGHT)
			change_light(global->scene, key);
		else if (global->scene->act_mod == MODE_OBJECT)
			change_object(global->scene, key);
		else if (global->scene->act_mod == MODE_MATERIAL)
			change_material(global->scene, key);
		else if (global->scene->act_mod == MODE_EFFECT)
			change_effect(global->scene, key);
		if (global->scene->act_mod == MODE_LIGHT ||
		global->scene->act_mod == MODE_MATERIAL)
			update_interface_only(global);
		else
			update_interface_and_frame(global);
	}
}

void	change_grade(t_global *global, int key)
{
	if (key == PLUS || key == MINUS || key == F)
	{
		if (global->scene->act_mod == MODE_LIGHT)
			change_light_intensity(global->scene, key);
		else if (global->scene->act_mod == MODE_EFFECT)
		{
			change_effect_grade(global->scene, key);
			update_interface_and_frame(global);
			return ;
		}
		else
			return ;
		draw(global);
	}
	else if (key == T)
	{
		global->scene->antialiasing = global->scene->antialiasing == TRUE ?
		FALSE : TRUE;
		if (global->scene->act_mod != MODE_EFFECT)
			draw(global);
	}
}

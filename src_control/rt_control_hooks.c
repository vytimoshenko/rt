/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:05:26 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:05:28 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

int	mouse_move(int x, int y, t_global *global)
{
	get_mouse_position(global->scene, x, y);
	update_interface_only(global);
	return (0);
}

int	mouse_key_press(int key, int x, int y, t_global *global)
{
	if (key == LEFT_MOUSE_BUTTON)
	{
		if (!(select_object(x, y, global)))
		{
			update_interface_and_frame(global);
			return (0);
		}
	}
	if (key == RIGHT_MOUSE_BUTTON)
	{
		pick_color(global->scene, x, y);
		update_interface_only(global);
		return (0);
	}
	else if (key == MIDDLE_MOUSE_BUTTON)
	{
		get_material(x, y, global);
		return (0);
	}
	update_interface_and_frame(global);
	return (0);
}

int	mouse_key_release(int key, int x, int y, t_global *global)
{
	if (key == MIDDLE_MOUSE_BUTTON && global->scene->mat_source
	!= NOTHING_SELECTED)
	{
		if (apply_material(x, y, global))
			draw(global);
	}
	return (0);
}

int	keyboard_key_press(int key, t_global *global)
{
	escape_key(global, key);
	change_mode_1(global, key);
	change_mode_2(global, key);
	change_item(global, key);
	change_grade(global, key);
	move_item(global, key);
	rotate_item(global, key);
	interface_actions(global, key);
	save_actions(global, key);
	reset(global, key);
	return (0);
}

int	close_window(t_global *global)
{
	clean_mlx(global->mlx);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control_interface.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:05:34 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:05:36 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	get_mouse_position(t_scene *scene, int x, int y)
{
	scene->x_mouse_pos = x - IMG_SIZE_W / 2 - IMG_INDT_W;
	scene->y_mouse_pos = IMG_SIZE_H / 2 - y + IMG_INDT_H;
	if (x < IMG_INDT_W || y < IMG_INDT_H || x > IMG_INDT_W + IMG_SIZE_W ||
	y > IMG_INDT_H + IMG_SIZE_H)
	{
		scene->x_mouse_pos = 0;
		scene->y_mouse_pos = 0;
	}
}

void	pick_color(t_scene *scene, int x, int y)
{
	int	i;

	x = x - IMG_INDT_W;
	y = y - IMG_INDT_H;
	if (x < 0 || x > IMG_SIZE_W || y < 0 || y > IMG_SIZE_H)
		return ;
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	scene->picked_color = scene->pix_buff[i].frame;
	scene->got_color = TRUE;
}

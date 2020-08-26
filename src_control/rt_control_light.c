/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:05:53 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:05:54 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	change_light(t_scene *scene, int key)
{
	if (key == MORE && scene->act_light != scene->lights.quant - 1)
		scene->act_light++;
	else if (key == MORE && scene->act_light == scene->lights.quant - 1)
		scene->act_light = 0;
	else if (key == LESS && scene->act_light != 0)
		scene->act_light--;
	else if (key == LESS && scene->act_light == 0)
		scene->act_light = scene->lights.quant - 1;
}

void	move_light(t_scene *scene, int key)
{
	int i;

	i = scene->act_light;
	if (key == ARROW_DOWN)
		scene->lights.arr[i]->pos.y -= OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_UP)
		scene->lights.arr[i]->pos.y += OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_RIGHT)
		scene->lights.arr[i]->pos.x += OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_LEFT)
		scene->lights.arr[i]->pos.x -= OBJECT_MOVEMENT_INCREMENT;
	else if (key == BRACKET_RIGHT)
		scene->lights.arr[i]->pos.z += OBJECT_MOVEMENT_INCREMENT;
	else if (key == BRACKET_LEFT)
		scene->lights.arr[i]->pos.z -= OBJECT_MOVEMENT_INCREMENT;
}

void	rotate_light(t_scene *scene, int key)
{
	int i;

	i = scene->act_light;
	if (key == W)
		scene->lights.arr[i]->dir.y += OBJECT_ROTATION_INCREMENT;
	else if (key == S)
		scene->lights.arr[i]->dir.y -= OBJECT_ROTATION_INCREMENT;
	else if (key == D)
		scene->lights.arr[i]->dir.x += OBJECT_ROTATION_INCREMENT;
	else if (key == A)
		scene->lights.arr[i]->dir.x -= OBJECT_ROTATION_INCREMENT;
	else if (key == Z)
		scene->lights.arr[i]->dir.z += OBJECT_ROTATION_INCREMENT;
	else if (key == X)
		scene->lights.arr[i]->dir.z -= OBJECT_ROTATION_INCREMENT;
}

void	change_light_intensity(t_scene *scene, int key)
{
	int i;

	i = scene->act_light;
	if (key == MINUS && scene->lights.arr[i]->intens >=
	LIGHT_INTENSITY_MIN + LIGHT_INTENSITY_INCREMENT)
		scene->lights.arr[i]->intens -= LIGHT_INTENSITY_INCREMENT;
	else if (key == PLUS && scene->lights.arr[i]->intens <
	LIGHT_INTENSITY_MAX)
		scene->lights.arr[i]->intens += LIGHT_INTENSITY_INCREMENT;
	if (key == B && scene->lights.arr[i]->off == TRUE)
		scene->lights.arr[i]->off = FALSE;
	else if (key == B && scene->lights.arr[i]->off == FALSE)
		scene->lights.arr[i]->off = TRUE;
}

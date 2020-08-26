/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:05:13 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:05:15 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	change_camera(t_scene *scene, int key)
{
	if (key == MORE && scene->act_cam != scene->cams.quant - 1)
		scene->act_cam++;
	else if (key == MORE && scene->act_cam == scene->cams.quant - 1)
		scene->act_cam = 0;
	else if (key == LESS && scene->act_cam != 0)
		scene->act_cam--;
	else if (key == LESS && scene->act_cam == 0)
		scene->act_cam = scene->cams.quant - 1;
	get_sin_cos(scene->cams.arr[scene->act_cam]);
}

void	move_camera(t_scene *scene, int key)
{
	int i;

	i = scene->act_cam;
	if (key == ARROW_DOWN)
		scene->cams.arr[i]->pos.y -= CAMERA_MOVEMENT_INCREMENT;
	else if (key == ARROW_UP)
		scene->cams.arr[i]->pos.y += CAMERA_MOVEMENT_INCREMENT;
	else if (key == ARROW_RIGHT)
		scene->cams.arr[i]->pos.x += CAMERA_MOVEMENT_INCREMENT;
	else if (key == ARROW_LEFT)
		scene->cams.arr[i]->pos.x -= CAMERA_MOVEMENT_INCREMENT;
	else if (key == BRACKET_RIGHT)
		scene->cams.arr[i]->pos.z += CAMERA_MOVEMENT_INCREMENT;
	else if (key == BRACKET_LEFT)
		scene->cams.arr[i]->pos.z -= CAMERA_MOVEMENT_INCREMENT;
}

void	rotate_camera(t_scene *scene, int key)
{
	int i;

	i = scene->act_cam;
	if (key == W)
		scene->cams.arr[i]->dir.x += CAMERA_ROTATION_INCREMENT;
	else if (key == S)
		scene->cams.arr[i]->dir.x -= CAMERA_ROTATION_INCREMENT;
	else if (key == D)
		scene->cams.arr[i]->dir.y += CAMERA_ROTATION_INCREMENT;
	else if (key == A)
		scene->cams.arr[i]->dir.y -= CAMERA_ROTATION_INCREMENT;
	else if (key == Z)
		scene->cams.arr[i]->dir.z += CAMERA_ROTATION_INCREMENT;
	else if (key == X)
		scene->cams.arr[i]->dir.z -= CAMERA_ROTATION_INCREMENT;
	get_sin_cos(scene->cams.arr[i]);
}

void	get_sin_cos(t_cam *camera)
{
	camera->sin.x = sin(deg_to_rad(camera->dir.x));
	camera->sin.y = sin(deg_to_rad(camera->dir.y));
	camera->sin.z = sin(deg_to_rad(camera->dir.z));
	camera->cos.x = cos(deg_to_rad(camera->dir.x));
	camera->cos.y = cos(deg_to_rad(camera->dir.y));
	camera->cos.z = cos(deg_to_rad(camera->dir.z));
}

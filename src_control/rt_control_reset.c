/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control_reset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:06:19 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/14 00:38:40 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	reset(t_global *global, int key)
{
	if (key == R && RESET_AVAILABLE)
	{
		clean_scene_1(global->scene);
		clean_scene_2(global->scene);
		clean_scene_3(global->scene);
		read_scene(global->scene, global->scene->file_name_with_path);
		set_initial_status(global->scene);
		get_lights_statistics(global->scene);
		get_objects_statistics(global->scene);
		set_initial_angles(global->scene);
		get_textures(global);
		draw(global);
	}
}

void	clean_scene_1(t_scene *scene)
{
	int	i;

	if (scene->name)
		free(scene->name);
	if (scene->author)
		free(scene->author);
	i = -1;
	while (++i < scene->cams.quant)
		free(scene->cams.arr[i]);
	free(scene->cams.arr);
	i = -1;
	while (++i < scene->lights.quant)
		free(scene->lights.arr[i]);
	free(scene->lights.arr);
}

void	clean_scene_2(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->mats.quant)
	{
		if (scene->mats.arr[i]->t)
			free(scene->mats.arr[i]->t);
		if (scene->mats.arr[i]->name)
			free(scene->mats.arr[i]->name);
		free(scene->mats.arr[i]);
	}
	free(scene->mats.arr);
	i = -1;
	while (++i < scene->objs.quant)
	{
		if (scene->objs.arr[i]->mat_name)
			free(scene->objs.arr[i]->mat_name);
		free(scene->objs.arr[i]);
	}
	free(scene->objs.arr);
}

void	clean_scene_3(t_scene *scene)
{
	int	i;

	if (scene->pix_buff)
		free(scene->pix_buff);
	i = -1;
	while (++i < MOTION_BLUR_BUFFERS)
		free(scene->motion_blur_buffs[i]);
	free(scene->motion_blur_buffs);
}

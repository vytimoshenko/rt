/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control_reset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:06:19 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:06:21 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	reset(t_global *global, int key)
{
	if (key == R)
	{
		clean_scene(global->scene);
		read_scene(global->scene, global->scene->file_name_with_path);
		set_initial_status(global->scene);
		get_lights_statistics(global->scene);
		get_objects_statistics(global->scene);
		set_initial_angles(global->scene);
		draw(global);
	}
}

void	clean_scene(t_scene *scene)
{
	int	i;

	free(scene->name);
	free(scene->author);
	i = -1;
	while (++i < scene->cams.quant)
		free(scene->cams.arr[i]);
	free(scene->cams.arr);
	i = -1;
	while (++i < scene->lights.quant)
		free(scene->lights.arr[i]);
	free(scene->lights.arr);
	i = -1;
	while (++i < scene->mats.quant)
		free(scene->mats.arr[i]);
	free(scene->mats.arr);
	i = -1;
	while (++i < scene->objs.quant)
		free(scene->objs.arr[i]);
	free(scene->objs.arr);
}

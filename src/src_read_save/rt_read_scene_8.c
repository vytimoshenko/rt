/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:49:40 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/13 20:12:03 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/rt.h"

void	check_material_names_unique(t_scene *scene)
{
	int	i;
	int	j;
	int	n;

	i = -1;
	while (++i < scene->mats.quant)
	{
		n = 0;
		j = -1;
		while (++j < scene->mats.quant)
		{
			if (!(ft_strcmp(scene->mats.arr[i]->name,
				scene->mats.arr[j]->name)))
				n++;
		}
		if (n != 1)
			put_error_wrong_scene_data(scene->objs.arr[i]->mat_name,
			"material name must be unique");
	}
}

void	find_objects_materials(t_scene *scene)
{
	int	i;
	int j;
	int	flag;

	i = -1;
	while (++i < scene->objs.quant)
	{
		j = -1;
		flag = 0;
		while (++j < scene->mats.quant)
		{
			if (!(ft_strcmp(scene->objs.arr[i]->mat_name,
			scene->mats.arr[j]->name)))
			{
				scene->objs.arr[i]->mat = j;
				flag = 1;
			}
		}
		if (flag == 0)
			put_error_wrong_scene_data(scene->objs.arr[i]->mat_name,
			"wrong object material name");
	}
}

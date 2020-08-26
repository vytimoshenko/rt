/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_save_scene_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:09:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:09:59 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	write_all_info(t_scene *scene, int fd)
{
	write_scene_info(scene, fd);
	write_cameras_info(scene, fd);
	write_lights_info(scene, fd);
	write_materials_info(scene, fd);
	write_objects_info(scene, fd);
}

void	write_scene_info(t_scene *scene, int fd)
{
	ft_putendl_fd(FILE_SCENE, fd);
	ft_putstr_fd("{\n\t", fd);
	ft_putstr_fd(FILE_SCENE_NAME, fd);
	ft_putstr_fd(":\t\t\"", fd);
	ft_putstr_fd(scene->name, fd);
	ft_putendl_fd("\";", fd);
	ft_putstr_fd("\t", fd);
	ft_putstr_fd(FILE_SCENE_AUTHOR, fd);
	ft_putstr_fd(":\t\t\"", fd);
	ft_putstr_fd(scene->author, fd);
	ft_putendl_fd("\";\n}\n", fd);
}

void	write_cameras_info(t_scene *scene, int fd)
{
	int	i;

	i = -1;
	while (++i < scene->cams.quant)
	{
		ft_putendl_fd(FILE_CAMERA, fd);
		ft_putstr_fd("{\n\t", fd);
		ft_putstr_fd(FILE_CAMERA_POSITION, fd);
		ft_putstr_fd(":\t[", fd);
		ft_putnbr_fd(scene->cams.arr[i]->pos.x, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->cams.arr[i]->pos.y, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->cams.arr[i]->pos.z, fd);
		ft_putstr_fd("];\n\t", fd);
		ft_putstr_fd(FILE_CAMERA_DIRECTION, fd);
		ft_putstr_fd(":\t[", fd);
		ft_putnbr_fd(scene->cams.arr[i]->dir.x, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->cams.arr[i]->dir.y, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->cams.arr[i]->dir.z, fd);
		ft_putendl_fd("];\n}\n", fd);
	}
}

void	write_lights_info(t_scene *scene, int fd)
{
	int	i;

	i = -1;
	while (++i < scene->lights.quant)
	{
		ft_putendl_fd(FILE_LIGHT, fd);
		ft_putstr_fd("{\n\t", fd);
		ft_putstr_fd(FILE_LIGHT_TYPE, fd);
		ft_putstr_fd(":\t\t", fd);
		ft_putstr_fd("<", fd);
		if (scene->lights.arr[i]->type == LIGHT_TYPE_AMBIENT)
			ft_putstr_fd(FILE_LIGHT_TYPE_AMBIENT, fd);
		else if (scene->lights.arr[i]->type == LIGHT_TYPE_DIRECTIONAL)
			ft_putstr_fd(FILE_LIGHT_TYPE_DIRECTIONAL, fd);
		else if (scene->lights.arr[i]->type == LIGHT_TYPE_POINT)
			ft_putstr_fd(FILE_LIGHT_TYPE_POINT, fd);
		ft_putstr_fd(">", fd);
		ft_putstr_fd(";\n\t", fd);
		ft_putstr_fd(FILE_LIGHT_INTENSITY, fd);
		ft_putstr_fd(":\t", fd);
		ft_putnbr_fd((int)(10 * scene->lights.arr[i]->intens), fd);
		write_lights_info_extra(scene, fd, i);
	}
}

void	write_lights_info_extra(t_scene *scene, int fd, int i)
{
	if (scene->lights.arr[i]->type == LIGHT_TYPE_AMBIENT)
		ft_putendl_fd(";\n}\n", fd);
	else
	{
		ft_putstr_fd(";\n\t", fd);
		ft_putstr_fd(FILE_LIGHT_POSITION, fd);
		ft_putstr_fd(":\t[", fd);
		ft_putnbr_fd(scene->lights.arr[i]->pos.x, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->lights.arr[i]->pos.y, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->lights.arr[i]->pos.z, fd);
		ft_putendl_fd("];\n}\n", fd);
	}
}

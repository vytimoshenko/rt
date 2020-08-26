/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_save_scene_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:02 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:10:04 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	write_materials_info(t_scene *scene, int fd)
{
	int	i;

	i = -1;
	while (++i < scene->mats.quant)
	{
		ft_putendl_fd(FILE_MATERIAL, fd);
		ft_putstr_fd("{\n\t", fd);
		ft_putstr_fd(FILE_MATERIAL_NAME	, fd);
		ft_putstr_fd(":\t\t\"", fd);
		ft_putstr_fd(scene->mats.arr[i]->name, fd);
		ft_putstr_fd("\";\n\t", fd);
		ft_putstr_fd(FILE_MATERIAL_COLOR, fd);
		ft_putstr_fd(":\t\t[", fd);
		ft_putnbr_fd(scene->mats.arr[i]->color.r, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->mats.arr[i]->color.g, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->mats.arr[i]->color.b, fd);
		ft_putstr_fd("];\n\t", fd);
		write_materials_info_extra(scene, fd, i);
	}
}

void	write_materials_info_extra(t_scene *scene, int fd, int i)
{
	ft_putstr_fd(FILE_MATERIAL_SPECULAR, fd);
	ft_putstr_fd(":\t", fd);
	ft_putnbr_fd(scene->mats.arr[i]->spec, fd);
	ft_putstr_fd(";\n\t", fd);
	ft_putstr_fd(FILE_MATERIAL_REFLECTIVE, fd);
	ft_putstr_fd(":\t", fd);
	ft_putnbr_fd((int)(10 * scene->mats.arr[i]->refl), fd);
	ft_putendl_fd(";\n}\n", fd);
}

void	write_objects_info(t_scene *scene, int fd)
{
	int	i;

	i = -1;
	while (++i < scene->objs.quant)
	{
		ft_putendl_fd(FILE_OBJECT, fd);
		ft_putstr_fd("{\n\t", fd);
		ft_putstr_fd(FILE_OBJECT_TYPE, fd);
		ft_putstr_fd(":\t\t", fd);
		ft_putstr_fd("<", fd);
		if (scene->objs.arr[i]->type == OBJECT_TYPE_PLANE)
			ft_putstr_fd(FILE_OBJECT_TYPE_PLANE, fd);
		else if (scene->objs.arr[i]->type == OBJECT_TYPE_SPHERE)
			ft_putstr_fd(FILE_OBJECT_TYPE_SPHERE, fd);
		else if (scene->objs.arr[i]->type == OBJECT_TYPE_CYLINDER)
			ft_putstr_fd(FILE_OBJECT_TYPE_CYLINDER, fd);
		else if (scene->objs.arr[i]->type == OBJECT_TYPE_CONE)
			ft_putstr_fd(FILE_OBJECT_TYPE_CONE, fd);
		ft_putstr_fd(">", fd);
		ft_putstr_fd(";\n\t", fd);
		write_objects_info_extra_1(scene, fd, i);
		write_objects_info_extra_2(scene, fd, i);
	}
}

void	write_objects_info_extra_1(t_scene *scene, int fd, int i)
{
	ft_putstr_fd(FILE_OBJECT_MATERIAL, fd);
	ft_putstr_fd(":\t\"", fd);
	ft_putstr_fd(scene->mats.arr
	[scene->objs.arr[i]->mat]->name, fd);
	ft_putstr_fd("\";\n\t", fd);
	ft_putstr_fd(FILE_OBJECT_POSITION, fd);
	ft_putstr_fd(":\t[", fd);
	ft_putnbr_fd(scene->objs.arr[i]->pos.x, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(scene->objs.arr[i]->pos.y, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(scene->objs.arr[i]->pos.z, fd);
	ft_putstr_fd("];\n\t", fd);
	ft_putstr_fd(FILE_OBJECT_ORIENTATION, fd);
	ft_putstr_fd(":\t[", fd);
	ft_putnbr_fd(scene->objs.arr[i]->dir.x, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(scene->objs.arr[i]->dir.y, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(scene->objs.arr[i]->dir.z, fd);
	ft_putstr_fd("];\n", fd);
}

void	write_objects_info_extra_2(t_scene *scene, int fd, int i)
{
	if (scene->objs.arr[i]->type != OBJECT_TYPE_PLANE)
	{
		ft_putstr_fd("\t", fd);
		ft_putstr_fd(FILE_OBJECT_RADIUS, fd);
		ft_putstr_fd(":\t\t", fd);
		ft_putnbr_fd(scene->objs.arr[i]->radius, fd);
		ft_putendl_fd(";\n}\n", fd);
	}
	else
		ft_putendl_fd("}\n", fd);
}

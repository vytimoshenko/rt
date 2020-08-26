/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_interface_material.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:08:12 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:08:14 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	info_material(t_scene *scene, t_mlx *mlx)
{
	int		x;
	int		y;

	x = WIN_SIZE_W - 350;
	y = 250;
	if (scene->act_mod == MODE_OBJECT)
		y = 350;
	info_material_1(scene, mlx, x, y);
	info_material_2(scene, mlx, x, y);
	info_material_3(scene, mlx, x, y);
}

void	info_material_1(t_scene *scene, t_mlx *mlx, int x, int y)
{
	int		i;
	char	*str;

	if (scene->act_mod == MODE_MATERIAL)
	{
		mlx_string_put(mlx->mlx, mlx->win, x + 80, y - 30, TEXT_COLOR,
	"MATERIAL CONTROL");
		i = scene->act_mat;
	}
	else
		i = scene->objs.arr[scene->act_obj]->mat;
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR,
	"Material:         #");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR,
	str = ft_itoa(i));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 210, y, TEXT_COLOR,
	scene->mats.arr[i]->name);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR,
	"- color (RGB):");
}

void	info_material_2(t_scene *scene, t_mlx *mlx, int x, int y)
{
	int		i;
	char	*str;

	if (scene->act_mod == MODE_MATERIAL)
		i = scene->act_mat;
	else
		i = scene->objs.arr[scene->act_obj]->mat;
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 30, TEXT_COLOR,
	str = ft_itoa(scene->mats.arr[i]->color.r));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 240, y + 30, TEXT_COLOR,
	str = ft_itoa(scene->mats.arr[i]->color.g));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 290, y + 30, TEXT_COLOR,
	str = ft_itoa(scene->mats.arr[i]->color.b));
	free(str);
}

void	info_material_3(t_scene *scene, t_mlx *mlx, int x, int y)
{
	int		i;
	char	*str;

	if (scene->act_mod == MODE_MATERIAL)
		i = scene->act_mat;
	else
		i = scene->objs.arr[scene->act_obj]->mat;
	info_material_color_sample(mlx,
	unite_color_channels(scene->mats.arr[i]->color),
	x + 150, y + 33);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
	"- specular:");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 50, TEXT_COLOR,
	str = ft_itoa(scene->mats.arr[i]->spec));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 70, TEXT_COLOR,
	"- reflective (x10):");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 70, TEXT_COLOR,
	str = ft_itoa(10 * scene->mats.arr[i]->refl));
	free(str);
}

void	info_material_color_sample(t_mlx *mlx, int color, int x, int y)
{
	int		x_rect;
	int		y_rect;

	y_rect = -1;
	while (++y_rect < 18)
	{
		x_rect = -1;
		while (++x_rect < 18)
			mlx_pixel_put(mlx->mlx, mlx->win, x_rect + x, y_rect + y, color);
	}
}

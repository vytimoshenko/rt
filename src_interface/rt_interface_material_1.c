/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_interface_material_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:08:12 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/11 23:25:44 by mperseus         ###   ########.fr       */
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
	info_material_4(scene, mlx, x, y);
}

void	info_material_1(t_scene *scene, t_mlx *mlx, int x, int y)
{
	int		i;
	char	*str;

	i = get_material_id(scene);
	if (scene->act_mod == MODE_MATERIAL)
		mlx_string_put(mlx->mlx, mlx->win, x + 80, y - 30, TEXT_COLOR,
	"MATERIAL CONTROL");
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR,
	"Material:         #");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR,
	str = ft_itoa(i));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 210, y, TEXT_COLOR,
	scene->mats.arr[i]->name);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR,
	"- texture type:");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
	"- texture name:");
}

void	info_material_2(t_scene *scene, t_mlx *mlx, int x, int y)
{
	int		i;

	i = get_material_id(scene);
	if (get_texture_type(scene) == NO_TEXTURE)
	{
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 30, TEXT_COLOR, "n/a");
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 50, TEXT_COLOR, "n/a");
	}
	if (get_texture_type(scene) == IMAGE_TEXTURE)
	{
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 30, TEXT_COLOR,
		"image");
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 50, TEXT_COLOR,
		trim_textures_path(scene->mats.arr[i]->t->name));
	}
	else if (get_texture_type(scene) == PROCEDURAL_TEXTURE)
	{
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 30, TEXT_COLOR,
		"procedural");
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 50, TEXT_COLOR,
		get_prcedural_texture_name(scene->mats.arr[i]->pattern));
	}
}

void	info_material_3(t_scene *scene, t_mlx *mlx, int x, int y)
{
	int		i;
	char	*str;
	int		color;

	i = get_material_id(scene);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 80, TEXT_COLOR,
	"- color (RGB):");
	if (get_texture_type(scene) != NO_TEXTURE)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 80, TEXT_COLOR, "n/a");
	else
	{
		color = unite_color_channels(scene->mats.arr[i]->color);
		color_sample(mlx, color, x + 160, y + 67);
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 80, TEXT_COLOR,
		str = ft_itoa(scene->mats.arr[i]->color.r));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, x + 240, y + 80, TEXT_COLOR,
		str = ft_itoa(scene->mats.arr[i]->color.g));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, x + 290, y + 80, TEXT_COLOR,
		str = ft_itoa(scene->mats.arr[i]->color.b));
		free(str);
	}
}

void	info_material_4(t_scene *scene, t_mlx *mlx, int x, int y)
{
	int		i;
	char	*str;

	i = get_material_id(scene);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 110, TEXT_COLOR,
	"- specular:");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 110, TEXT_COLOR,
	str = ft_itoa(scene->mats.arr[i]->spec));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 130, TEXT_COLOR,
	"- reflect (x10):");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 130, TEXT_COLOR,
	str = ft_itoa(10 * scene->mats.arr[i]->refl));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 160, TEXT_COLOR,
	"- transparency:       %");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 160, TEXT_COLOR,
	str = ft_itoa(100 * scene->mats.arr[i]->transp));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 180, TEXT_COLOR,
	"- refract (x10):");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 180, TEXT_COLOR,
	str = ft_itoa(10 * scene->mats.arr[i]->refr));
	free(str);
}

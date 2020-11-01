/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_interface_material_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:08:12 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/01 17:15:39 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	color_sample(t_mlx *mlx, int color, int x, int y)
{
	int	x_rect;
	int	y_rect;

	y_rect = -1;
	while (++y_rect < 18)
	{
		x_rect = -1;
		while (++x_rect < 18)
			mlx_pixel_put(mlx->mlx, mlx->win, x_rect + x, y_rect + y, color);
	}
}

int		get_material_id(t_scene *scene)
{	
	if (scene->act_mod == MODE_MATERIAL)
		return scene->act_mat;
	return scene->objs.arr[scene->act_obj]->mat;
}

int		get_texture_type(t_scene *scene)
{
	int	i;

	i = get_material_id(scene);
	if (scene->mats.arr[i]->pattern != 0)
		return PROCEDURAL_TEXTURE;
	else if (scene->mats.arr[i]->t != NULL)
		return IMAGE_TEXTURE;
	return NO_TEXTURE;
}

char	*get_prcedural_texture_name(int pattern)
{
	if (pattern == STRIPE_X)
		return "Stripe X";
	else if (pattern == STRIPE_Y)
		return "Stripe Y";
	else if (pattern == CHECKER)
		return "Checkerboard";
	else if (pattern == WAVE)
		return "Waves";
	else if (pattern == PERLIN_N)
		return "Perlin Noise";
	else if (pattern == WOOD)
		return "Wood";
	else if (pattern == MARBLE)
		return "Marble";
	return "Unknown type";
}

char 	*trim_textures_path(char *path)
{
	int len;

	len = ft_strlen(TEXTURES_PATH);
	while (len > 0) {
		path++;
		len--;
	}
	return path;
}

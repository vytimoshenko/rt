/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_interface_bottom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:07:34 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:07:36 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	info_coordinates(t_scene *scene, t_mlx *mlx)
{
	int		x;
	int		y;
	char	*str;

	x = 20;
	y = WIN_SIZE_H - 30;
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR, "X:      Y:");
	mlx_string_put(mlx->mlx, mlx->win, x + 20, y, TEXT_COLOR,
	str = ft_itoa(scene->x_mouse_pos));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 100, y, TEXT_COLOR,
	str = ft_itoa(scene->y_mouse_pos));
	free(str);
}

void	info_color(t_scene *scene, t_mlx *mlx)
{
	int		x;
	int		y;
	char	*str;

	x = 230;
	y = WIN_SIZE_H - 30;
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR, "R:     G:     B:");
	mlx_string_put(mlx->mlx, mlx->win, x + 20, y, TEXT_COLOR,
	str = ft_itoa((int)scene->picked_color.r));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 90, y, TEXT_COLOR,
	str = ft_itoa((int)scene->picked_color.g));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 160, y, TEXT_COLOR,
	str = ft_itoa((int)scene->picked_color.b));
	free(str);
	info_color_sample(mlx, unite_color_channels(scene->picked_color));
}

void	info_color_sample(t_mlx *mlx, int color)
{
	int		x;
	int		y;
	int		x_rect;
	int		y_rect;

	x = 200;
	y = WIN_SIZE_H - 27;
	y_rect = -1;
	while (++y_rect < 18)
	{
		x_rect = -1;
		while (++x_rect < 18)
			mlx_pixel_put(mlx->mlx, mlx->win, x_rect + x, y_rect + y, color);
	}
}

void	info_scene_file_name(t_scene *scene, t_mlx *mlx)
{
	int	x;
	int	y;

	x = 80;
	y = WIN_SIZE_H - 30;
	mlx_string_put(mlx->mlx, mlx->win, x + 370, y, TEXT_COLOR,
	scene->file_name_with_path);
}

void	info_help_string(t_mlx *mlx)
{
	int	x;
	int	y;

	x = WIN_SIZE_W - 300;
	y = WIN_SIZE_H - 55;
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR,
	"<< PRESS H FOR HELP >>");
}

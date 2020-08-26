/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_interface_render.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:08:45 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:08:47 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	info_render(t_mlx *mlx)
{
	int		x;
	int		y;

	x = WIN_SIZE_W - 350;
	y = WIN_SIZE_H - 200;
	info_render_1(mlx, x, y);
	info_render_2(mlx, x, y);
}

void	info_render_1(t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x + 115, y, TEXT_COLOR,
	"RENDER");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR,
	"Resolition:          x      pixels");
	mlx_string_put(mlx->mlx, mlx->win, x + 160, y + 30, TEXT_COLOR,
	str = ft_itoa(IMG_SIZE_W));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 230, y + 30, TEXT_COLOR,
	str = ft_itoa(IMG_SIZE_H));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
	"Pixels:");
	mlx_string_put(mlx->mlx, mlx->win, x + 160, y + 50, TEXT_COLOR,
	str = ft_itoa(IMG_SIZE_W * IMG_SIZE_H));
	free(str);
}

void	info_render_2(t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x, y + 80, TEXT_COLOR,
	"Frames:");
	mlx_string_put(mlx->mlx, mlx->win, x + 160, y + 80, TEXT_COLOR,
	str = ft_itoa(mlx->frames));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 100, TEXT_COLOR,
	"Frame time:          ms");
	mlx_string_put(mlx->mlx, mlx->win, x + 160, y + 100, TEXT_COLOR,
	str = ft_itoa(mlx->frame_time));
	free(str);
}

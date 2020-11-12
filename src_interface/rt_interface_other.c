/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_interface_other.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:08:39 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/12 19:57:53 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	info_message_box(t_mlx *mlx, char *title, char *message)
{
	int	x;
	int	y;

	x = (WIN_SIZE_W - MESSAGE_BOX_W) / 2;
	y = (WIN_SIZE_H - MESSAGE_BOX_H) / 2 + 20;
	info_draw_box(mlx, MESSAGE_BOX_W, MESSAGE_BOX_H);
	mlx_string_put(mlx->mlx, mlx->win, x + MESSAGE_BOX_W / 2 -
	10 * ft_strlen(title) / 2, y + MESSAGE_BOX_INDENTATION, TEXT_COLOR, title);
	mlx_string_put(mlx->mlx, mlx->win, x + MESSAGE_BOX_W / 2 -
	10 * ft_strlen(message) / 2, y + MESSAGE_BOX_H / 2, TEXT_COLOR, message);
}

void	info_message_box_bar(t_mlx *mlx, char *title, char *message, double i)
{
	int	x;
	int	y;

	x = (WIN_SIZE_W - MESSAGE_BOX_W) / 2;
	y = (WIN_SIZE_H - MESSAGE_BOX_H) / 2;
	info_draw_box(mlx, MESSAGE_BOX_W, MESSAGE_BOX_H + 30);
	info_draw_bar(mlx, i);
	mlx_string_put(mlx->mlx, mlx->win, x + MESSAGE_BOX_W / 2 -
	10 * ft_strlen(title) / 2, y + MESSAGE_BOX_INDENTATION, TEXT_COLOR, title);
	mlx_string_put(mlx->mlx, mlx->win, x + MESSAGE_BOX_W / 2 -
	10 * ft_strlen(message) / 2, y + MESSAGE_BOX_H / 2, TEXT_COLOR, message);
}

void	info_draw_box(t_mlx *mlx, int size_w, int size_h)
{
	int	x;
	int	y;
	int	x_rect;
	int	y_rect;

	x = (WIN_SIZE_W - size_w) / 2;
	y = (WIN_SIZE_H - size_h) / 2;
	y_rect = -1;
	while (++y_rect < size_h)
	{
		x_rect = -1;
		while (++x_rect < size_w)
			mlx_pixel_put(mlx->mlx, mlx->win, x_rect + x, y_rect + y,
			DEEPBLACK_BOX_COLOR);
	}
}

void	info_draw_bar(t_mlx *mlx, double i)
{
	int	x;
	int	y;
	int	x_rect;
	int	y_rect;

	x = (WIN_SIZE_W - PROGRESS_BAR_W) / 2;
	y = (WIN_SIZE_H - PROGRESS_BAR_H) / 2 + PROGRESS_BAR_INDENTATION;
	y_rect = -1;
	while (++y_rect < PROGRESS_BAR_H)
	{
		x_rect = -1;
		while (++x_rect < PROGRESS_BAR_W)
			mlx_pixel_put(mlx->mlx, mlx->win, x_rect + x, y_rect + y,
			x_rect / (double)PROGRESS_BAR_W < i ? PROGRESS_BAR_FILLED_COLOR :
			PROGRESS_BAR_UNFILLED_COLOR);
	}
}

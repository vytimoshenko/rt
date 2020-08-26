/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_interface_other.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:08:39 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:08:41 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	info_draw_box(t_mlx *mlx, int size_w, int size_h)
{
	int		x;
	int		y;
	int		x_rect;
	int		y_rect;

	x = (WIN_SIZE_W - size_w) / 2;
	y = (WIN_SIZE_H - size_h) / 2;
	y_rect = -1;
	while (++y_rect < size_h)
	{
		x_rect = -1;
		while (++x_rect < size_w)
			mlx_pixel_put(mlx->mlx, mlx->win, x_rect + x, y_rect + y,
			BOX_COLOR);
	}
}

void	info_message_box(t_mlx *mlx, char *message_title, char *message_content)
{
	int		x;
	int		y;

	x = (WIN_SIZE_W - MESSAGE_BOX_W) / 2;
	y = (WIN_SIZE_H - MESSAGE_BOX_H) / 2;
	info_draw_box(mlx, MESSAGE_BOX_W, MESSAGE_BOX_H);
	mlx_string_put(mlx->mlx, mlx->win, x + MESSAGE_BOX_W / 2 -
	10 * ft_strlen(message_title) / 2, y + MESSAGE_BOX_INDENTATION, TEXT_COLOR,
	message_title);
	mlx_string_put(mlx->mlx, mlx->win, x + MESSAGE_BOX_W / 2 -
	10 * ft_strlen(message_content) / 2, y + MESSAGE_BOX_H / 2, TEXT_COLOR,
	message_content);
}

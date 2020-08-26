/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_interface_help_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:07:50 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:07:52 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	show_help(t_mlx *mlx)
{
	int x;
	int y;

	x = (WIN_SIZE_W - HELP_BOX_W) / 2 + INFO_BOX_INDENTATION;
	y = (WIN_SIZE_H - HELP_BOX_H) / 2 + INFO_BOX_INDENTATION;
	info_draw_box(mlx, HELP_BOX_W, HELP_BOX_H);
	info_header_and_author(mlx, x + 400, y);
	info_help_general(mlx, x + 10, y + 50);
	info_help_effect(mlx, x + 10, y + 240);
	info_help_camera(mlx, x + 10, y + 390);
	info_help_light(mlx, x + 520, y + 50);
	info_help_material(mlx, x + 520, y + 240);
	info_help_object(mlx, x + 520, y + 370);
}

void	info_header_and_author(t_mlx *mlx, int x, int y)
{
	mlx_string_put(mlx->mlx, mlx->win, x, y - 10, TEXT_COLOR,
	"-= rt =-");
	mlx_string_put(mlx->mlx, mlx->win, x - 60, y + 10, TEXT_COLOR,
	"basic raytracing render");
	mlx_string_put(mlx->mlx, mlx->win, x + 20, y + 540, TEXT_COLOR,
	"-= Developed by mperseus at 21 School, Moscow, 2020 =-");
}

void	info_help_general(t_mlx *mlx, int x, int y)
{
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR,
	"                 GENERAL");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR,
	"Save as:                    U");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
	"Pick color:                 right mouse button");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 70, TEXT_COLOR,
	"Reset:                      R");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 90, TEXT_COLOR,
	"Help:                       H");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 110, TEXT_COLOR,
	"Scene summary info:         I");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 130, TEXT_COLOR,
	"Exit:                       Q");
}

void	info_help_effect(t_mlx *mlx, int x, int y)
{
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR,
	"                 EFFECTS");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR,
	"Effect control mode:        E");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
	"Change effect:              </>");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 70, TEXT_COLOR,
	"Change effect grade:        +/-");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 90, TEXT_COLOR,
	"Antialiasing on/off:        T");
}

void	info_help_camera(t_mlx *mlx, int x, int y)
{
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR,
	"                 CAMERAS");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR,
	"Camera control mode:        ESC");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
	"Change camera:              </>");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 70, TEXT_COLOR,
	"Move camera:                arrows/[/]");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 90, TEXT_COLOR,
	"Rotate camera:              W/A/S/D/Z/X");
}

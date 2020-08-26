/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_interface_help_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:07:56 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:07:58 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	info_help_light(t_mlx *mlx, int x, int y)
{
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR,
	"              LIGHT SOURCES");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR,
	"Light source control mode:  L");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
	"Change light source:        </>");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 70, TEXT_COLOR,
	"Move light source:          arrows/[/]");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 90, TEXT_COLOR,
	"Turn on/off light source:   B");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 110, TEXT_COLOR,
	"Light source intensity:     +/-");
}

void	info_help_material(t_mlx *mlx, int x, int y)
{
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR,
	"                MATERIALS");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR,
	"Material control mode:      M");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
	"Change material:            </>");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 70, TEXT_COLOR,
	"Apply material to object:   middle mouse button");
}

void	info_help_object(t_mlx *mlx, int x, int y)
{
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR,
	"                 OBJECTS");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR,
	"Object control mode:        O");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
	"Change object:              </>");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 70, TEXT_COLOR,
	"Select object:              left mouse button");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 90, TEXT_COLOR,
	"Cancel selection:           ESC");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 110, TEXT_COLOR,
	"Move object:                arrows/[/]");
}

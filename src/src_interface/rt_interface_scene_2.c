/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_interface_scene_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:08:50 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/14 05:55:13 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/rt.h"

void	info_scene_5(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 180, TEXT_COLOR,
	"- paraboloids:");
	mlx_string_put(mlx->mlx, mlx->win, x + 350, y + 180, TEXT_COLOR,
	str = ft_itoa(scene->objs.quant_paraboloids));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 200, TEXT_COLOR,
	"- hyperboloids:");
	mlx_string_put(mlx->mlx, mlx->win, x + 350, y + 200, TEXT_COLOR,
	str = ft_itoa(scene->objs.quant_hyperboloids));
	free(str);
}

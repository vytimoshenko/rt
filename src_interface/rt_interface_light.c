/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_interface_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:08:01 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:08:03 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	info_light(t_scene *scene, t_mlx *mlx)
{
	int	x;
	int	y;

	x = WIN_SIZE_W - 350;
	y = 250;
	info_light_1(scene, mlx, x, y);
	info_light_2(scene, mlx, x, y);
	info_light_3(scene, mlx, x, y);
}

void	info_light_1(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x + 90, y - 30, TEXT_COLOR,
	"LIGHT CONTROL");
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR,
	"Light source:     #");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR,
	str = ft_itoa(scene->act_light));
	free(str);
	if (scene->lights.arr[scene->act_light]->type == LIGHT_TYPE_AMBIENT)
		mlx_string_put(mlx->mlx, mlx->win, x + 210, y, TEXT_COLOR, "Ambient");
	else if (scene->lights.arr[scene->act_light]->type ==
	LIGHT_TYPE_DIRECTIONAL)
		mlx_string_put(mlx->mlx, mlx->win, x + 210, y, TEXT_COLOR,
	"Directional");
	else if (scene->lights.arr[scene->act_light]->type == LIGHT_TYPE_POINT)
		mlx_string_put(mlx->mlx, mlx->win, x + 210, y, TEXT_COLOR, "Point");
}

void	info_light_2(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR, "- switch:");
	if (scene->lights.arr[scene->act_light]->off == FALSE)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 30, TEXT_COLOR, "on");
	else if (scene->lights.arr[scene->act_light]->off == TRUE)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 30, TEXT_COLOR, "off");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
	"- intensity (x10):");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 50, TEXT_COLOR,
	str = ft_itoa(10 * scene->lights.arr[scene->act_light]->intens));
	free(str);
}

void	info_light_3(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	if (scene->lights.arr[scene->act_light]->type ==
	LIGHT_TYPE_POINT || scene->lights.arr[scene->act_light]->type ==
	LIGHT_TYPE_DIRECTIONAL)
	{
		mlx_string_put(mlx->mlx, mlx->win, x, y + 70, TEXT_COLOR,
		"- position (XYZ):");
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 70, TEXT_COLOR,
		str = ft_itoa(scene->lights.arr[scene->act_light]->pos.x));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, x + 240, y + 70, TEXT_COLOR,
		str = ft_itoa(scene->lights.arr[scene->act_light]->pos.y));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, x + 290, y + 70, TEXT_COLOR,
		str = ft_itoa(scene->lights.arr[scene->act_light]->pos.z));
		free(str);
	}
}

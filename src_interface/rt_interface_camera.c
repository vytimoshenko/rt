/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_interface_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:07:40 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:07:41 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	info_camera(t_scene *scene, t_mlx *mlx)
{
	int	x;
	int	y;

	x = WIN_SIZE_W - 350;
	y = 30;
	info_camera_1(scene, mlx, x, y);
	info_camera_2(scene, mlx, x, y);
}

void	info_camera_1(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x + 110, y, TEXT_COLOR, "CAMERA #");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR,
	str = ft_itoa(scene->act_cam + 1));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR,
	"- position (XYZ):");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 30, TEXT_COLOR,
	str = ft_itoa(scene->cams.arr[scene->act_cam]->pos.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 240, y + 30, TEXT_COLOR,
	str = ft_itoa(scene->cams.arr[scene->act_cam]->pos.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 290, y + 30, TEXT_COLOR,
	str = ft_itoa(scene->cams.arr[scene->act_cam]->pos.z));
	free(str);
}

void	info_camera_2(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
	"- rotation (XYZ):");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 50, TEXT_COLOR,
	str = ft_itoa(scene->cams.arr[scene->act_cam]->dir.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 240, y + 50, TEXT_COLOR,
	str = ft_itoa(scene->cams.arr[scene->act_cam]->dir.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 290, y + 50, TEXT_COLOR,
	str = ft_itoa(scene->cams.arr[scene->act_cam]->dir.z));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 90, TEXT_COLOR, "Antialiasing:");
	if (scene->antialiasing == TRUE)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 90, TEXT_COLOR, "on");
	else if (scene->antialiasing == FALSE)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 90, TEXT_COLOR, "off");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_interface_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:08:32 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/01 22:57:31 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	info_object(t_scene *scene, t_mlx *mlx)
{
	int		x;
	int		y;

	x = WIN_SIZE_W - 350;
	y = 250;
	info_object_1(scene, mlx, x, y);
	info_object_2(scene, mlx, x, y);
	info_object_3(scene, mlx, x, y);
}

void	info_object_1(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x + 80, y - 30, TEXT_COLOR,
	"OBJECT CONTROL");
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR, "Object/group:");
	mlx_string_put(mlx->mlx, mlx->win, x + 180, y, TEXT_COLOR, "# /");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR,
	str = ft_itoa(scene->act_obj));
	free(str);
	if (scene->objs.arr[scene->act_obj]->group == NO_GROUP)
		mlx_string_put(mlx->mlx, mlx->win, x + 210, y, TEXT_COLOR, "-");
	else
		mlx_string_put(mlx->mlx, mlx->win, x + 210, y, TEXT_COLOR,
		str = ft_itoa(scene->objs.arr[scene->act_obj]->group));
	if (scene->objs.arr[scene->act_obj]->type == OBJECT_TYPE_PLANE)
		mlx_string_put(mlx->mlx, mlx->win, x + 230, y, TEXT_COLOR, "Plane");
	else if (scene->objs.arr[scene->act_obj]->type == OBJECT_TYPE_SPHERE)
		mlx_string_put(mlx->mlx, mlx->win, x + 230, y, TEXT_COLOR, "Sphere");
	else if (scene->objs.arr[scene->act_obj]->type == OBJECT_TYPE_CONE)
		mlx_string_put(mlx->mlx, mlx->win, x + 230, y, TEXT_COLOR, "Cone");
	else if (scene->objs.arr[scene->act_obj]->type == OBJECT_TYPE_CYLINDER)
		mlx_string_put(mlx->mlx, mlx->win, x + 230, y, TEXT_COLOR, "Cylinder");
}

void	info_object_2(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR,
	"- position (XYZ):");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 30, TEXT_COLOR,
	str = ft_itoa(scene->objs.arr[scene->act_obj]->pos.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 240, y + 30, TEXT_COLOR,
	str = ft_itoa(scene->objs.arr[scene->act_obj]->pos.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 290, y + 30, TEXT_COLOR,
	str = ft_itoa(scene->objs.arr[scene->act_obj]->pos.z));
	free(str);
}

void	info_object_3(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	if (scene->objs.arr[scene->act_obj]->type == OBJECT_TYPE_PLANE)
	{
		info_object_4(scene, mlx, x, y);
		return ;
	}
	mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
	"- radius/length:       /");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 50, TEXT_COLOR,
	str = ft_itoa(scene->objs.arr[scene->act_obj]->radius));
	free(str);
	if (scene->objs.arr[scene->act_obj]->len != 0)
	{
		mlx_string_put(mlx->mlx, mlx->win, x + 250, y + 50, TEXT_COLOR,
		str = ft_itoa(scene->objs.arr[scene->act_obj]->len));
		free(str);
	}
	else if (scene->objs.arr[scene->act_obj]->type != OBJECT_TYPE_SPHERE)
		mlx_string_put(mlx->mlx, mlx->win, x + 250, y + 50, TEXT_COLOR,
		"infinity");
	else
		mlx_string_put(mlx->mlx, mlx->win, x + 250, y + 50, TEXT_COLOR, "n/a");
}

void	info_object_4(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	if (scene->objs.arr[scene->act_obj]->radius == 0)
		return ;
	mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
	"- radius:");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 50, TEXT_COLOR,
	str = ft_itoa(scene->objs.arr[scene->act_obj]->radius));
	free(str);
}

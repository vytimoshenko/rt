/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:15 by mperseus          #+#    #+#             */
/*   Updated: 2020/09/03 14:05:03 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	int i;

	i = (int)(y * mlx->size_line / 4) + x;
	if (i < IMG_SIZE_H * IMG_SIZE_W)
		mlx->data[i] = color;
}

void	my_draw(t_mlx *mlx)
{
	for (int i = 0; i <= 100; ++i)
	{
		for (int j = 0; j <= 100; ++j)
		{
			pixel_put(mlx, j, i, 0x00FF00);
//			mlx->data[i + j] = 0x00FF00;
//			my_mlx_pixel_put(mlx, j, i, 0x00FF00);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	draw_texture(t_global *global)
{
	int i = -1, j = -1;
	int w = 0, h = 0;


	w = global->scene->texture->t_w;
	h = global->scene->texture->t_h;
	while (++i < IMG_SIZE_H * IMG_SIZE_W)
		global->mlx->data[i] = 0;
	i = -1;
	while (++i < h * (h / IMG_SIZE_H))
	{
		j = -1;
		while (++j < w)
			pixel_put(global->mlx, j, i, global->scene->texture->addr
			[i * global->scene->texture->size_line / 4 + j]);
	}
	mlx_put_image_to_window(global->mlx->mlx, global->mlx->win,
							global->mlx->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_global	global;

	global.scene = init_scene(argc, argv);
	global.mlx = init_mlx();
	global.scene->texture = (t_texture [1]){{0}};
	texture(&global);
	t_obj 		o = {global.scene->objs.quant, OBJECT_TYPE_SPHERE, 0, {255, 0 , 0}
			, 0, 0, 0, 0, 10, {10, 3, 30}
			, {0, 1, 0}, {0, 0, 0}, {0, 0, 0}
			, 0, global.scene->texture, 0, 0, 0, 0};
	global.scene->objs.arr[global.scene->objs.quant - 1] = &o;
	global.scene->objs.quant_spheres++;
//	my_draw(global.mlx);
//	draw_texture(&global);
	draw(&global);
	loop(&global);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:32:58 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/28 20:47:26 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		get_patt_color(t_pnt *pnt, t_obj *obj, t_double2 uv, t_mat *mat)
{
	if (mat->pattern >= STRIPE_X && mat->pattern <= STRIPE_Y)
		return (stripe_pattern(obj, uv, mat));
	else if (mat->pattern == CHECKER)
		return (checker_pattern(uv, pnt, obj));
	else if (mat->pattern == WAVE)
		return (wave_pattern(uv, mat));
	else if (mat->pattern == PERLIN_N)
		return (perlin_noise(obj));
	else if (mat->pattern == WOOD)
		return (wood(obj));
	else if (mat->pattern == MARBLE)
		return (marble(obj));
	return (0);
}

int		get_image_texel(t_mat *mat, t_obj *obj)
{
	t_double2	uv;
	int			height;
	int			weight;
	int			texel;

	uv = (t_double2){obj->uv.u, obj->uv.v};
	if (uv.u < 0)
		uv.u = 0;
	if (uv.v < 0)
		uv.v = 0;
	if (uv.u > 1.0)
		uv.u = 1.0;
	if (uv.v > 1.0)
		uv.v = 1.0;
	uv.v = 1 - uv.v;
	height = (int)(uv.v * (mat->t->t_h));
	weight = (int)(uv.u * (mat->t->t_w));
	if (height >= mat->t->t_h)
		height = mat->t->t_h - 1;
	if (weight >= mat->t->t_w)
		weight = mat->t->t_w - 1;
	texel = height * mat->t->size_line / 4 + weight;
	return ((mat->t->addr[texel] & 16) | (mat->t->addr[texel] & 8)
	| mat->t->addr[texel]);
}

int		identify_patt_tex(t_pnt *pnt, t_obj *obj, t_double2 uv, t_mat *mat)
{
	if (mat->t)
		return (get_image_texel(mat, obj));
	else
		return (get_patt_color(pnt, obj, uv, mat));
}

// Function for initialisation textures
void	init_texture(t_texture *texture, t_mlx *mlx)
{
//	TODO можно ли добавлять другие текстуры для чтения?
//	TODO Переделать открытие текстур под SDL2 or libpng
	texture->data = mlx_png_file_to_image(mlx->mlx, texture->name
			, &texture->t_w, &texture->t_h);
	texture->addr = (int *)mlx_get_data_addr(texture->data
			, &texture->bits_per_pixel, &texture->size_line, &texture->endian);
}

int		get_textures(t_global *g)
{
	int i;

	i = -1;
	while (++i < g->scene->objs.quant)
	{
		if (g->scene->mats.arr[g->scene->objs.arr[i]->mat]->t)
			init_texture(
					g->scene->mats.arr[g->scene->objs.arr[i]->mat]->t, g->mlx);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:32:58 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/25 18:45:41 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

int identify_patt_tex(t_pnt *pnt, t_obj *obj, t_double2 uv, t_mat *mat)
{
	if (mat->t)
		return (get_image_texel(mat, obj));
	else
		return (get_patt_color(pnt, obj, uv, mat));
}

//TODO очистить и отнормировать функцию
int		get_image_texel(t_mat *mat, t_obj *obj)
{
	double u = obj->uv.u;
	double v = obj->uv.v;
	int 	height;
	int 	weight;

	if (u < 0)
		u = 0;
	if (v < 0)
		v = 0;
	if (u > 1.0)
		u = 1.0;
	if (v > 1.0)
		v = 1.0;

	v = 1 - v;

	height = (int )(v * (mat->t->t_h));
	weight = (int )(u * (mat->t->t_w));
	if (height >= mat->t->t_h)
		height = mat->t->t_h - 1;
	if (weight >= mat->t->t_w)
		weight = mat->t->t_w - 1;
//		int texel = height + weight * obj->t->size_line / 4;
//	int texel = 4 +  height * mat->t->size_line / 4  + weight;
	int texel = height * mat->t->size_line / 4  + weight;
//		int *texel = obj->t->addr + height * obj->t->size_line / 4 + weight * obj->t->bits_per_pixel;
//	printf("%d\n", texel);
//	int c_scale = 1.0 / 255.0;
//		t_clr clr = {c_scale * texel[0], c_scale * texel[1], c_scale * texel[2]};
//		if (texel < (obj->t->t_h * obj->t->t_w))
//			pnt->color = integer_to_rgb(obj->t->addr[abs(texel)]);
//	return (mat->t->addr[texel]);
	return (mat->t->addr[texel] & 16 |  mat->t->addr[texel] & 8 |  mat->t->addr[texel]);
//		pnt->color = clr;

}

// Function for initialisation textures
void 	init_texture(t_texture *texture, t_mlx *mlx)
{
	//	char	*path = "textures/ljagushonok-pepe.png";
	//	char	*path = "textures/316-3166191_sphere.png";
	//	char	*path = "textures/300840060233211.png";
	//	char	*path = "textures/earthmap1k.png";
	//	char	*path = "textures/burning+hot+lava-1024x1024.png";
//	char	*path = "textures/yellow+bananas-2048x2048.png";

//	TODO Переделать открытие текстур под SDL2 or libpng
	texture->data = mlx_png_file_to_image(mlx->mlx, texture->name, &texture->t_w
									   , &texture->t_h);
	texture->addr = (int *)mlx_get_data_addr(texture->data
			, &texture->bits_per_pixel, &texture->size_line, &texture->endian);
//		scene->get_textures->t_h = llenght / (bpp / 8);
//		scene->get_textures->t_w = llenght / (bpp / 8);
//	init_obj_texture(scene);
}


int		get_textures(t_global *g)
{
	int i = -1;
	while (++i < g->scene->objs.quant)
	{
		if (g->scene->mats.arr[g->scene->objs.arr[i]->mat]->t)
			init_texture(g->scene->mats.arr[g->scene->objs.arr[i]->mat]->t, g->mlx);
	}
	return (0);
}
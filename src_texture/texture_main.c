/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:32:58 by wquirrel          #+#    #+#             */
/*   Updated: 2020/11/09 19:47:45 by mperseus         ###   ########.fr       */
/*   Updated: 2020/11/08 20:09:37 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

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

int		get_image_texel(double *trns, t_mat *mat, t_obj *obj)
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
//	texel = height * mat->t->size_line / 4 + weight;

	texel = height * mat->t->t_w + weight;
//	*trns = 1 - ((double)(mat->t->addr[texel] & (0xFF << 24))) / 255;

//	return ((mat->t->addr[texel] & 16) | (mat->t->addr[texel] & 8)
//	| mat->t->addr[texel]);
//	return ((mat->t->addr[texel] << 24) & 255 | (mat->t->addr[texel + 2] << 16) & 255 | (mat->t->addr[texel + 1] << 8) & 255 | mat->t->addr[texel]);
	return texel;
}

int		identify_patt_tex(t_pnt *pnt, t_obj *obj, t_double2 uv, t_mat *mat, double *trns)
{
	int texel;

	texel = 0;
	if (mat->t)
	{
		texel = get_image_texel(&mat->transp, mat, obj);
		*trns = 1 - ((double)(mat->t->addr[texel] & (0xFF << 24))) / 255;
		return ((mat->t->addr[texel] & 16) | (mat->t->addr[texel] & 8)
		| mat->t->addr[texel]);
	}
	else
		return (get_patt_color(pnt, obj, uv, mat));
}

void	init_texture(t_texture *texture, t_mlx *mlx)
{
//	 if (SDL_Init(SDL_INIT_EVERYTHING))
//	  put_error_pn("SDL_Init");
	SDL_Surface *surface = IMG_Load(texture->name);
	if (surface == NULL)
		ft_put_errno("SDL2 Unable to load image");
	printf("loaded image: %dx%d\n", surface->w, surface->h);
	// texture->data = mlx_new_image(mlx->mlx, surface->w, surface->h);
	texture->t_w = surface->w;
	texture->t_h = surface->h;
//	 SDL_PixelFormat *format = SDL_AllocFormat(SDL_PIXELFORMAT_ARGB32);
//	 SDL_Surface *surface1 = SDL_ConvertSurface(surface, format, 0);
//	 SDL_FreeFormat(format);
//	 SDL_FreeSurface(surface);
//	texture->data = mlx_png_file_to_image(mlx->mlx, texture->name
//			, &texture->t_w, &texture->t_h);
//	texture->addr = (int *)mlx_get_data_addr(texture->data
//			, &texture->bits_per_pixel, &texture->size_line, &texture->endian);
	 texture->addr = (Uint32 *)surface->pixels;
	// SDL_FreeSurface(surface);
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

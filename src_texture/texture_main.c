/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:32:58 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/10 20:30:43 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

/*
void	spherical_map(t_vec p, t_obj sp, double *u, double *v)
{
	double theta = atan2(p.y, p.z);
	t_vec vec = p;
	double radius = sp.radius;
	double phi = acos(p.y / radius);
	double raw_u = theta / (2 * PI);
	*u = 1 - (raw_u + 0.5);
	*v = 1 - phi / PI;
}

double uv_pattern_at(checkers, u, v)
{
	double u2 = u * T_WIDTH;
	double v2 = v * T_HEIGHT;

	if ((int)(u2 + v2) % 2 == 0)
		return T_COLOR_R;
	else
		return T_COLOR_G;
}
*/

void	init_obj_texture(t_scene *s)
{
	int i = -1;
	while (++i < s->objs.quant)
	{
		if (s->objs.arr[i]->t)
			s->objs.arr[i]->t = s->texture;
	}
}


int		texture(t_global *g)
{
	void	*img;
	int 	*addr;
//	char	*path = "textures/ljagushonok-pepe.png";
//	char	*path = "textures/brick-wall.png";
//	char	*path = "textures/316-3166191_sphere.png";
	char	*path = "textures/300840060233211.png";
//	char	*path = "textures/earthmap1k.png";
//	char	*path = "textures/burning+hot+lava-1024x1024.png";
//	char	*path = "textures/yellow+bananas-2048x2048.png";
	int		img_width;
	int 	img_height;
	int 	bpp;
	int 	llenght;
	int		endian;

	img = mlx_png_file_to_image(g->mlx->mlx, path, &img_width, &img_height);
	addr = (int *)mlx_get_data_addr(img, &bpp, &llenght, &endian);
	g->scene->texture->data = img;
	g->scene->texture->addr = addr;
//	g->scene->texture->t_h = llenght / (bpp / 8);
//	g->scene->texture->t_w = llenght / (bpp / 8);
	g->scene->texture->t_h = img_height;
	g->scene->texture->t_w = img_width;
	g->scene->texture->bits_per_pixel = bpp;
	g->scene->texture->size_line = llenght;
	g->scene->texture->endian = endian;
	init_obj_texture(g->scene);
	return (0);
}
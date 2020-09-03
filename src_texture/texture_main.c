/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:32:58 by wquirrel          #+#    #+#             */
/*   Updated: 2020/09/03 17:32:48 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

int		texture(t_global *g)
{
	void	*img;
	int 	*addr;
	char	*path = "textures/ljagushonok-pepe.png";
//	char	*path = "textures/pngwing.com.png";
	int		img_width;
	int 	img_height;
	int 	bpp;
	int 	llenght;
	int		endian;

	img = mlx_png_file_to_image(g->mlx->mlx, path, &img_width, &img_height);
	addr = (int *)mlx_get_data_addr(img, &bpp, &llenght, &endian);
	g->scene->texture->data = img;
	g->scene->texture->addr = addr;
	g->scene->texture->t_h = img_height;
	g->scene->texture->t_w = img_width;
	g->scene->texture->bits_per_pixel = bpp;
	g->scene->texture->size_line = llenght;
	g->scene->texture->endian = endian;
/*	for (int i = 0; i < img_height; ++i)
	{
		for (int j = 0; j < img_width; ++j)
		{
			printf("%d ", addr[i + j]);
		}
		printf("\n");
	}*/
	return (0);
}
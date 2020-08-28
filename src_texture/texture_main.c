/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:32:58 by wquirrel          #+#    #+#             */
/*   Updated: 2020/08/28 20:48:45 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

int		texture(t_global *g)
{
	void	*img;
	int 	*addr;
	char	*path = "textures/ljagushonok-pepe.png";
	int		img_width;
	int 	img_height;
	int 	bpp;
	int 	llenght;
	int		endian;

	img = mlx_png_file_to_image(g->mlx->mlx, path, &img_width, &img_height);
	g->scene->texture = (int *)mlx_get_data_addr(img, &bpp, &llenght, &endian);
	return (0)
}
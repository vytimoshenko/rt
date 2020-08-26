/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_effect_pixelation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:07:25 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:07:27 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	effect_pixelation(t_scene *scene)
{
	int		x;
	int		y;
	int		pitch;
	t_clr	color;

	y = 0;
	while (y < IMG_SIZE_H / scene->k_pixelation)
	{
		x = 0;
		while (x < IMG_SIZE_W / scene->k_pixelation)
		{
			pitch = x * scene->k_pixelation + y * IMG_SIZE_W *
			scene->k_pixelation;
			color = get_average_color(scene, pitch);
			draw_macro_pixel(scene, color, pitch);
			x++;
		}
		y++;
	}
}

t_clr	get_average_color(t_scene *scene, int pitch)
{
	int		i;
	int		y;
	t_vec	color;

	color = (t_vec){0, 0, 0};
	y = 0;
	while (y < scene->k_pixelation)
	{
		i = pitch + y * IMG_SIZE_W - 1;
		while (i++ < pitch + y * IMG_SIZE_W - 1 + scene->k_pixelation)
		{
			color.x += scene->pix_buff[i].color.r;
			color.y += scene->pix_buff[i].color.g;
			color.z += scene->pix_buff[i].color.b;
		}
		y++;
	}
	color.x /= scene->k_pixelation * scene->k_pixelation;
	color.y /= scene->k_pixelation * scene->k_pixelation;
	color.z /= scene->k_pixelation * scene->k_pixelation;
	return ((t_clr){color.x, color.y, color.z});
}

void	draw_macro_pixel(t_scene *scene, t_clr color, int pitch)
{
	int i;
	int y;

	y = 0;
	while (y < scene->k_pixelation)
	{
		i = pitch + y * IMG_SIZE_W - 1;
		while (i++ < pitch + y * IMG_SIZE_W - 1 + scene->k_pixelation)
			scene->pix_buff[i].frame = color;
		y++;
	}
}

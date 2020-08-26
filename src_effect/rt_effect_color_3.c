/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_effect_color_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:06:53 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:06:55 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

t_clr	to_grayscale(t_clr color)
{
	int tmp;

	tmp = 0.2126 * color.r + 0.7152 * color.g + 0.0722 * color.b;
	color.r = tmp;
	color.g = tmp;
	color.b = tmp;
	return (color);
}

t_clr	to_negative(t_clr color)
{
	color.r ^= 0xFF;
	color.g ^= 0xFF;
	color.b ^= 0xFF;
	return (color);
}

t_clr	to_cartoon(t_scene *scene, t_clr color)
{
	color.r /= scene->k_cartoon;
	color.g /= scene->k_cartoon;
	color.b /= scene->k_cartoon;
	color.r *= scene->k_cartoon;
	color.g *= scene->k_cartoon;
	color.b *= scene->k_cartoon;
	return (color);
}

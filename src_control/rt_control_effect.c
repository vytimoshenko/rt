/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control_effect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:05:20 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:05:22 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	change_effect(t_scene *scene, int key)
{
	if (key == MORE && scene->act_eff != EFFECTS_QUANTITY - 1)
		scene->act_eff++;
	else if (key == MORE && scene->act_eff == EFFECTS_QUANTITY - 1)
		scene->act_eff = 0;
	else if (key == LESS && scene->act_eff != 0)
		scene->act_eff--;
	else if (key == LESS && scene->act_eff == 0)
		scene->act_eff = EFFECTS_QUANTITY - 1;
}

void	change_effect_grade(t_scene *scene, int key)
{
	if (scene->act_eff == EFFECT_CARTOON)
	{
		if (key == MINUS && scene->k_cartoon > CARTOON_MIN)
			scene->k_cartoon /= CARTOON_INCREMENT;
		else if (key == PLUS && scene->k_cartoon < CARTOON_MAX)
			scene->k_cartoon *= CARTOON_INCREMENT;
	}
	else if (scene->act_eff == EFFECT_PIXELATION)
	{
		if (key == MINUS && scene->k_pixelation > PIXELATION_MIN)
			scene->k_pixelation /= PIXELATION_INCREMENT;
		else if (key == PLUS && scene->k_pixelation < PIXELATION_MAX)
			scene->k_pixelation *= PIXELATION_INCREMENT;
	}
	else if (scene->act_eff == EFFECT_DEPTH)
	{
		if (key == MINUS && scene->k_depth_map > DEPTH_MAP_MIN)
			scene->k_depth_map /= DEPTH_MAP_INCREMENT;
		else if (key == PLUS && scene->k_depth_map < DEPTH_MAP_MAX)
			scene->k_depth_map *= DEPTH_MAP_INCREMENT;
	}
}

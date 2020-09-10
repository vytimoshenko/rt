/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_textures.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 19:13:05 by wquirrel          #+#    #+#             */
/*   Updated: 2020/09/09 12:48:57 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RT_RT_TEXTURES_H
#define RT_RT_TEXTURES_H

# define T_WIDTH 16
# define T_HEIGHT 8
# define T_COLOR_R 0xFF0000
# define T_COLOR_G 0xFF00
# define T_COLOR_B 0xFF
# define T_COLOR_BL 0x0
# define T_COLOR_W 0xFFFFFF


# include "rt_structures.h"

enum e_coord
{
	P_X,
	P_Y,
	P_Z
};

typedef enum e_patterns
{
	STRIPE_X = 1,
	STRIPE_Y,
	STRIPE_Z
}			t_patterns;

int		texture(t_global *g);
int		choose_pattern(t_pnt *pnt, t_obj *obj);

#endif //RT_RT_TEXTURES_H

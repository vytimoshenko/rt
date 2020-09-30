/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_textures.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 19:13:05 by wquirrel          #+#    #+#             */
/*   Updated: 2020/09/30 19:02:54 by wquirrel         ###   ########.fr       */
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
# define CHECKER_W 16
# define CHECKER_H 16
# define CHECKER_W_S 16
# define CHECKER_H_S 32


# include "rt_structures.h"

enum e_coord
{
	P_X,
	P_Y,
	P_Z
};

enum e_patterns
{
	STRIPE_X = 1,
	STRIPE_Y,
	STRIPE_Z,
	CHECKER
};

void	get_uv(t_pnt *p, t_obj *obj, t_double2 *uv);
t_double2	get_plane_texel(t_obj *obj, t_pnt *p);
int		texture(t_global *g);
int		choose_pattern(t_pnt *pnt, t_obj *obj, t_double2 uv);

#endif //RT_RT_TEXTURES_H

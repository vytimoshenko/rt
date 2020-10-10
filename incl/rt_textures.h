/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_textures.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 19:13:05 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/03 18:22:08 by wquirrel         ###   ########.fr       */
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
# define CHECKER_W 32
# define CHECKER_H 16
# define STRIPE 10
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
//	STRIPE_Z,
	CHECKER
};

void	get_uv(t_pnt *p, t_obj *obj, t_double2 *uv);
t_double2	get_plane_texel_g(t_obj *obj, t_pnt *p);
t_double2	get_plane_texel_l(t_obj *obj, t_pnt *p);
int		texture(t_global *g);
int		choose_pattern(t_pnt *pnt, t_obj *obj, t_double2 uv);

#endif //RT_RT_TEXTURES_H

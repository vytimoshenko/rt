/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_textures.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 19:13:05 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/25 19:33:23 by wquirrel         ###   ########.fr       */
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
# define P_SIZE 256
# define P_MASK 255



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
	CHECKER,
	WAVE,
	PERLIN_N,
	WOOD,
	MARBLE
};

void	get_uv(t_pnt *p, t_obj *obj, t_double2 *uv);
t_double2	get_plane_texel_g(t_obj *obj, t_pnt *p);
t_double2	get_plane_texel_l(t_obj *obj, t_pnt *p);
void	init_p();
int		get_textures(t_global *g);
int		get_image_texel(t_mat *mat, t_obj *obj);
int 	identify_patt_tex(t_pnt *pnt, t_obj *obj, t_double2 uv, t_mat *mat);
int 	get_patt_color(t_pnt *pnt, t_obj *obj, t_double2 uv, t_mat *mat);
int		stripe_pattern(t_obj *obj, t_double2 uv, t_mat *mat);
int 	perlin_noise(t_obj *obj);
int		wood(t_obj *obj);
int		marble(t_obj *obj);
void	free_texture(t_texture *t);
t_clr	integer_to_rgb(int clr);
int		rgb_to_integer(t_clr clr);

#endif //RT_RT_TEXTURES_H

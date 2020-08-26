/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_effect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:03:38 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:03:41 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef rt_EFFECT_H

# define rt_EFFECT_H

# include "rt.h"

# define SHADE_UNSELECTED				0.5

# define EFFECTS_QUANTITY				7
# define EFFECT_GRAYSCALE				0
# define EFFECT_NEGATIVE				1
# define EFFECT_CARTOON					2
# define EFFECT_PIXELATION				3
# define EFFECT_OUTLINE					4
# define EFFECT_DEPTH					5
# define EFFECT_ANAGLYPH				6

# define CARTOON_INCREMENT				2
# define CARTOON_INIT					16
# define CARTOON_MIN					8
# define CARTOON_MAX					64

# define PIXELATION_INCREMENT			2
# define PIXELATION_INIT				16
# define PIXELATION_MIN					4
# define PIXELATION_MAX					64

# define DEPTH_MAP_INCREMENT			2
# define DEPTH_MAP_INIT					128
# define DEPTH_MAP_MIN					32
# define DEPTH_MAP_MAX					512

# define ANTIALIASING_COLOR_THRESHOLD	32
# define ANTIALIASING_OUTLINE_WIDTH		6
# define MULTI_SAMPLING_RATE			16

void		final_processing(t_mlx *mlx, t_scene *scene);
t_clr		pixel_post_processing(t_scene *scene, int i, t_clr color);

void		fill_aliasing_buffer(t_scene *scene);
int			need_to_smooth(t_scene *scene, int i);
void		add_adjacent_pixels(t_scene *scene, int i);
t_clr		effect_outline(t_scene *scene, int i);

void		run_antialiasing(t_scene *scene);
void		get_jitter(double *random);
void		get_multisample_color(t_scene *scene, t_pix *pixel, double *rand);

void		effect_pixelation(t_scene *scene);
t_clr		get_average_color(t_scene *scene, int pitch);
void		draw_macro_pixel(t_scene *scene, t_clr color, int pitch);

t_clr		shade_unselesected(t_scene *scene, int i, t_clr color);
t_clr		effect_depth(t_scene *scene, int i);
void		effect_anaglyph(t_scene *scene);

int			unite_color_channels(t_clr color);
t_clr		average_color_channels(t_clr color);
t_clr		split_color(int color);
t_clr		get_channel_diff(t_clr c1, t_clr c2);

t_clr		add_color(t_clr c1, t_clr c2);
t_clr		multiply_color(double k, t_clr c);
t_clr		mix_color(t_clr c1, t_clr c2);

t_clr		to_grayscale(t_clr color);
t_clr		to_negative(t_clr color);
t_clr		to_cartoon(t_scene *scene, t_clr color);

#endif

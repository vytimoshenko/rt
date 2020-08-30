/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:04:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:04:33 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef rt_STRUCTURES_H

# define rt_STRUCTURES_H

# include "rt.h"

typedef struct			s_vec
{
	double				x;
	double				y;
	double				z;
}						t_vec;

typedef struct			s_clr
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_clr;

typedef struct			s_pix
{
	int					i;
	int					x;
	int					y;
	t_vec				pos;
	t_clr				color;
	double				depth;
	short				obj_id;
	bool				aliasing;
	t_clr				anaglyph;
	t_clr				frame;
}						t_pix;

typedef struct			s_pnt
{
	t_vec				xyz;
	t_clr				color;
	double				spec;
	double				refl;
	double				refr;
	double				trns;
	double				light;
	t_vec				n;
	double				light_intens;
	t_clr				final_clr;
}						t_pnt;

typedef struct			s_mn_mx
{
	double				t;
	double				t_min;
	double				t_max;
}						t_mn_mx;

typedef struct			s_cam
{
	int					id;
	t_vec				pos;
	t_vec				dir;
	t_vec				sin;
	t_vec				cos;
}						t_cam;

typedef struct			s_obj
{
	int					id;
	int					type;
	int					mat;
	t_clr				color;
	double				spec;
	double				refl;
	double				refr;
	double				transp;
	double				radius;
	t_vec				pos;
	t_vec				dir;
	t_vec				sin;
	t_vec				cos;
	double				k;

	double				t1;
	double				t2;
	double				closest;
	int					null;
}						t_obj;

typedef struct			s_light
{
	int					id;
	int					type;
	int					off;
	double				intens;
	t_vec				pos;
	t_vec				dir;
}						t_light;

typedef struct			s_mat
{
	int					id;
	char				*name;
	t_clr				color;
	double				spec;
	double				refl;
	double				transp;
	double				refr;
}						t_mat;

typedef struct			s_cams
{
	int					quant;
	t_cam				**arr;
}						t_cams;

typedef struct			s_lights
{
	int					quant;
	int					quant_ambient;
	int					quant_directional;
	int					quant_point;
	t_light				**arr;
}						t_lights;

typedef struct			s_mats
{
	int					quant;
	t_mat				**arr;
}						t_mats;

typedef struct			s_objs
{
	int					quant;
	int					quant_planes;
	int					quant_spheres;
	int					quant_cylinders;
	int					quant_cones;
	t_obj				**arr;
}						t_objs;

typedef struct			s_scene
{
	char				*file_name_with_path;
	char				*name;
	char				*author;
	t_cams				cams;
	t_lights			lights;
	t_objs				objs;
	t_mats				mats;

	int					act_mod;
	int					act_cam;
	int					act_light;
	int					act_mat;
	int					act_obj;
	int					act_eff;

	t_pix				*pix_buff;

	int					antialiasing;
	int					k_cartoon;
	int					k_pixelation;
	int					k_depth_map;

	int					got_color;
	t_clr				picked_color;
	int					mat_source;
	int					x_mouse_pos;
	int					y_mouse_pos;
	int					middle_mouse_button;

	int					show_help;
	int					show_info;

	t_pnt				pnt;
	t_obj				obj;
}						t_scene;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	int					*data;

	int					bits_per_pixel;
	int					size_line;
	int					endian;

	int					frames;
	float				frame_time;
}						t_mlx;

typedef	struct	s_sdl
{
	SDL_Renderer	*render;
	SDL_Window		*window;
}				t_sdl;

typedef struct			s_global
{
	t_scene				*scene;
	t_mlx				*mlx;
	t_sdl				sdl;
}						t_global;

#endif

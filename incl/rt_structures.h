/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:04:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/08 17:49:03 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCTURES_H

# define RT_STRUCTURES_H

# include "rt.h"

typedef struct			s_double2
{
	double u;
	double v;
}						t_double2;

typedef struct			s_clr
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_clr;

typedef struct			s_texture
{
	void				*data;
	char				*name;
	Uint32 				*addr;
	int					t_w;
	int					t_h;

	int					bits_per_pixel;
	int					size_line;
	int					endian;
	float				t_x;
	float				t_y;
	t_clr				clr;
}						t_texture;
//TODO Нужна ли эта структура?
typedef struct			s_textures
{
	int					quantity;
	t_texture			*tex;
}						t_textures;

typedef struct			s_vec
{
	double				x;
	double				y;
	double				z;
}						t_vec;

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
	double				angle;
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
	int					group;
	int					type;
	int					mat;
	int					pattern;
	int					rec;
	int					neg;
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
	double				len;
	t_double2			uv;

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
	int					pattern;
	char				*name;
	t_clr				color;
	double				spec;
	double				refl;
	double				refr;
	double				transp;
	double				angle;
	double				scale;
	t_vec				shift;
	t_texture			*t;
	int					alpha;
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

	t_texture			*texture;

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

typedef struct			s_global
{
	t_scene				*scene;
	t_mlx				*mlx;
}						t_global;

typedef struct			s_peace
{
	t_scene				*scene;
	pthread_t			p;
	int					i;
}						t_peace;

#endif

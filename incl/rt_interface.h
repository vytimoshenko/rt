/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_interface.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:03:45 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/13 20:41:17 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_INTERFACE_H

# define RT_INTERFACE_H

# include "rt.h"

# define WIN_SIZE_W						1370
# define WIN_SIZE_H						808
# define IMG_SIZE_W						960.0
# define IMG_SIZE_H						768.0
# define IMG_INDT_W						10
# define IMG_INDT_H						10

# define SHOW_RENDERING_PROGRESS_BAR	1

# define TEXT_COLOR 					0xFFFFFFFF
# define DEEPBLACK_BOX_COLOR			0x00000000
# define PROGRESS_BAR_FILLED_COLOR		0x00FFFFFF
# define PROGRESS_BAR_UNFILLED_COLOR	0x00222222

# define HELP_BOX_W						1070
# define HELP_BOX_H						600

# define INFO_BOX_W						420
# define INFO_BOX_H						280

# define INFO_BOX_INDENTATION			30

# define MESSAGE_BOX_W					500
# define MESSAGE_BOX_H					80
# define MESSAGE_BOX_INDENTATION		10

# define PROGRESS_BAR_W					400
# define PROGRESS_BAR_H					16
# define PROGRESS_BAR_INDENTATION		30

# define NO_TEXTURE						0
# define IMAGE_TEXTURE					1
# define PROCEDURAL_TEXTURE				2

void		show_interface(t_global *global);

void		info_camera(t_scene *scene, t_mlx *mlx);
void		info_camera_1(t_scene *scene, t_mlx *mlx, int x, int y);
void		info_camera_2(t_scene *scene, t_mlx *mlx, int x, int y);

void		info_light(t_scene *scene, t_mlx *mlx);
void		info_light_1(t_scene *scene, t_mlx *mlx, int x, int y);
void		info_light_2(t_scene *scene, t_mlx *mlx, int x, int y);
void		info_light_3(t_scene *scene, t_mlx *mlx, int x, int y);

void		info_material(t_scene *scene, t_mlx *mlx);
void		info_material_1(t_scene *scene, t_mlx *mlx, int x, int y);
void		info_material_2(t_scene *scene, t_mlx *mlx, int x, int y);
void		info_material_3(t_scene *scene, t_mlx *mlx, int x, int y);
void		info_material_4(t_scene *scene, t_mlx *mlx, int x, int y);

void		color_sample(t_mlx *mlx, int color, int x, int y);
int			get_material_id(t_scene *scene);
int			get_texture_type(t_scene *scene);
char		*get_prcedural_texture_name(int pattern);
char		*trim_textures_path(char *path);

void		info_object(t_scene *scene, t_mlx *mlx);
void		info_object_1(t_scene *scene, t_mlx *mlx, int x, int y);
void		info_object_2(t_scene *scene, t_mlx *mlx, int x, int y);
void		info_object_3(t_scene *scene, t_mlx *mlx, int x, int y);
void		info_object_4(t_scene *scene, t_mlx *mlx, int x, int y);

void		info_effect(t_scene *scene, t_mlx *mlx);
void		info_effect_1(t_scene *scene, t_mlx *mlx, int x, int y);
void		info_effect_2(t_scene *scene, t_mlx *mlx, int x, int y);
void		info_effect_3(t_scene *scene, t_mlx *mlx, int x, int y);

void		info_render(t_mlx *mlx);
void		info_render_1(t_mlx *mlx, int x, int y);
void		info_render_2(t_mlx *mlx, int x, int y);

void		info_coordinates(t_scene *scene, t_mlx *mlx);
void		info_color(t_scene *scene, t_mlx *mlx);
void		info_scene_file_name(t_scene *scene, t_mlx *mlx);
void		info_help_string(t_mlx *mlx);

void		info_scene(t_scene *scene, t_mlx *mlx);
void		info_scene_1(t_scene *scene, t_mlx *mlx, int x, int y);
void		info_scene_2(t_scene *scene, t_mlx *mlx, int x, int y);
void		info_scene_3(t_scene *scene, t_mlx *mlx, int x, int y);
void		info_scene_4(t_scene *scene, t_mlx *mlx, int x, int y);

void		info_scene_5(t_scene *scene, t_mlx *mlx, int x, int y);

void		show_help(t_mlx *mlx);
void		info_header_and_author(t_mlx *mlx, int x, int y);
void		info_help_general(t_mlx *mlx, int x, int y);
void		info_help_effect(t_mlx *mlx, int x, int y);
void		info_help_camera(t_mlx *mlx, int x, int y);

void		info_help_light(t_mlx *mlx, int x, int y);
void		info_help_material(t_mlx *mlx, int x, int y);
void		info_help_object(t_mlx *mlx, int x, int y);

void		info_message_box(t_mlx *mlx, char *title, char *message);
void		info_message_box_bar(t_mlx *mlx, char *title, char *message,
			double i);
void		info_draw_box(t_mlx *mlx, int size_w, int size_h);
void		info_draw_bar(t_mlx *mlx, double i);

#endif

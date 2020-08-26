/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_save.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:04:15 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:04:17 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef rt_READ_SAVE_H

# define rt_READ_SAVE_H

# include "rt.h"

# define SAVE_PATH						"./saves/"
# define SCENE_FILE_EXTENSION			".rt"
# define SAVE_MESSAGE_TITLE				"SCENE SAVED AS"
# define CURRENT_TIME_STR_LENGTH		24

# define READ_BUFF_SIZE					8192

# define FILE_PARSE_SCENE				0
# define FILE_PARSE_CAMERA				1
# define FILE_PARSE_LIGHT				2
# define FILE_PARSE_MATERIAL			3
# define FILE_PARSE_OBJECT				4

# define FILE_SCENE						"scene"
# define FILE_SCENE_NAME				"name"
# define FILE_SCENE_AUTHOR				"author"
# define FILE_CAMERA					"camera"
# define FILE_CAMERA_POSITION			"position"
# define FILE_CAMERA_DIRECTION			"direction"
# define FILE_LIGHT						"light"
# define FILE_LIGHT_TYPE				"type"
# define FILE_LIGHT_TYPE_AMBIENT		"ambient"
# define FILE_LIGHT_TYPE_DIRECTIONAL	"directional"
# define FILE_LIGHT_TYPE_POINT			"point"
# define FILE_LIGHT_INTENSITY			"intensity"
# define FILE_LIGHT_POSITION			"position"
# define FILE_MATERIAL					"material"
# define FILE_MATERIAL_NAME				"name"
# define FILE_MATERIAL_COLOR			"color"
# define FILE_MATERIAL_SPECULAR			"specular"
# define FILE_MATERIAL_REFLECTIVE		"reflective"
# define FILE_OBJECT					"object"
# define FILE_OBJECT_TYPE				"type"
# define FILE_OBJECT_TYPE_PLANE			"plane"
# define FILE_OBJECT_TYPE_SPHERE		"sphere"
# define FILE_OBJECT_TYPE_CYLINDER		"cylinder"
# define FILE_OBJECT_TYPE_CONE			"cone"
# define FILE_OBJECT_MATERIAL			"material"
# define FILE_OBJECT_POSITION			"position"
# define FILE_OBJECT_ORIENTATION		"orientation"
# define FILE_OBJECT_RADIUS				"radius"

void		read_scene(t_scene *scene, char *file_name);
void		divide_to_items(t_scene *scene, char *line);
int			count_items(char *line);
int			parse_each_item(t_scene *scene, char **items_array);

int			count_items_by_type(t_scene *scene, char *item_line);
int			define_item_type(t_scene *scene, char *type);
void		put_error_wrong_scene_data(char *wrong_data, char *message);
void		save_quantities(t_scene *scene);
void		allocate_memory(t_scene *scene);

int			parse_item_line(t_scene *scene, char *item_line);
int			parse_item_description(t_scene *scene, int type_id,
			char *description);
char		*prepare_value_to_write(char *value);
char		*any_whitespace_to_space(char *value);
void		str_free(char **property, char **value, char **prepared_value);

void		parse_item_by_property(t_scene *scene, int type_id, char *property,
			char *value);
void		parse_scene_description(t_scene *scene, char *property,
			char *value);
void		parse_camera_description(t_scene *scene, char *property,
			char *value);
void		parse_light_description(t_scene *scene, char *property,
			char *value);
int			find_light_type(char *value);

void		parse_material_description(t_scene *scene, char *property,
			char *value);
void		parse_object_description(t_scene *scene, char *property,
			char *value);
int			find_object_type(char *value);
int			find_object_material(t_scene *scene, char *value);

t_vec		parse_vector(char *value);
t_clr		parse_color(char *value);
int			check_and_get_int_value(char *value);
void		validate_color(char *value, t_vec color);

char		*delete_whitespaces(char *line);
int			count_whitespaces(char *line);
int			is_whitespace(char c);
void		copy_without_whitespaces(char *line, char *clean_line);

void		save_scene(t_scene *scene, t_mlx *mlx);
void		create_save_file_name(t_scene *scene, char **file_name);
void		get_current_time_string(char *time_string);

void		write_all_info(t_scene *scene, int fd);
void		write_scene_info(t_scene *scene, int fd);
void		write_cameras_info(t_scene *scene, int fd);
void		write_lights_info(t_scene *scene, int fd);
void		write_lights_info_extra(t_scene *scene, int fd, int i);

void		write_materials_info(t_scene *scene, int fd);
void		write_materials_info_extra(t_scene *scene, int fd, int i);
void		write_objects_info(t_scene *scene, int fd);
void		write_objects_info_extra_1(t_scene *scene, int fd, int i);
void		write_objects_info_extra_2(t_scene *scene, int fd, int i);

void		save_screenshot(t_scene *scene, t_mlx *mlx);
void		create_screenshot_file_name(t_scene *scene, char **file_name);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:03:24 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:03:27 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef rt_CONTROL_H

# define rt_CONTROL_H

# include "rt.h"

# define NOTHING_SELECTED				-1

# define MODE_CAMERA	                0
# define MODE_LIGHT 	                1
# define MODE_MATERIAL	                2
# define MODE_OBJECT	                3
# define MODE_EFFECT	                4

# define CAMERA_MOVEMENT_INCREMENT		10
# define CAMERA_ROTATION_INCREMENT		15

# define LIGHT_INTENSITY_INCREMENT		0.1
# define LIGHT_INTENSITY_MAX			1.0
# define LIGHT_INTENSITY_MIN			0.0

# define OBJECT_MOVEMENT_INCREMENT		10
# define OBJECT_ROTATION_INCREMENT		30

# define BUTTON_UP						0
# define BUTTON_DOWN					1
# define IN_MOVE						2

# define LEFT_MOUSE_BUTTON				1
# define RIGHT_MOUSE_BUTTON				2
# define MIDDLE_MOUSE_BUTTON			3
# define MOUSE_SCROLL_UP				4
# define MOUSE_SCROLL_DOWN				5

# define A								0
# define S								1
# define D								2
# define H								4
# define Z								6
# define X								7
# define B								11
# define Q								12
# define W								13
# define E								14
# define R								15
# define T								17
# define PLUS							24
# define MINUS							27
# define BRACKET_RIGHT					30
# define O								31
# define U								32
# define BRACKET_LEFT					33
# define I								34
# define P								35
# define L								37
# define LESS							43
# define M								46
# define MORE							47
# define ESC							53
# define ARROW_LEFT						123
# define ARROW_RIGHT					124
# define ARROW_DOWN						125
# define ARROW_UP						126

void	loop(t_global *global);

int		mouse_move(int x, int y, t_global *global);
int		mouse_key_press(int key, int x, int y, t_global *global);
int		mouse_key_release(int key, int x, int y, t_global *global);
int		keyboard_key_press(int key, t_global *global);
int		close_window(t_global *global);

void	escape_key(t_global *global, int key);
void	change_mode_1(t_global *global, int key);
void	change_mode_2(t_global *global, int key);
void	change_item(t_global *global, int key);
void	change_grade(t_global *global, int key);

void	move_item(t_global *global, int key);
void	rotate_item(t_global *global, int key);
void	interface_actions(t_global *global, int key);
void	save_actions(t_global *global, int key);

void	change_camera(t_scene *scene, int key);
void	move_camera(t_scene *scene, int key);
void	rotate_camera(t_scene *scene, int key);
void	get_sin_cos(t_cam *camera);

void	change_light(t_scene *scene, int key);
void	move_light(t_scene *scene, int key);
void	change_light_intensity(t_scene *scene, int key);

void	change_material(t_scene *scene, int key);
void	get_material(int x, int y, t_global *global);
int		apply_material(int x, int y, t_global *global);

int		select_object(int x, int y, t_global *global);
void	change_object(t_scene *scene, int key);
void	move_object(t_scene *scene, int key);

void	change_effect(t_scene *scene, int key);
void	change_effect_grade(t_scene *scene, int key);

void	get_mouse_position(t_scene *scene, int x, int y);
void	pick_color(t_scene *scene, int x, int y);

void	reset(t_global *global, int key);
void	clean_scene(t_scene *scene);

#endif

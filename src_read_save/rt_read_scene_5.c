/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:09:36 by mperseus          #+#    #+#             */
/*   Updated: 2020/10/25 19:58:04 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

int 		check_png(char *file)
{
	char *string;

	string = ft_strchr(file, '.');
	if (ft_strequ(string, "png"))
		return (-1);
	return (0);
}

t_texture 	*identify_texture(char *tex)
{
	t_texture *t;
	char *path;

	path = "textures/";
	path = ft_strjoin(path, tex);
	if (check_png(ft_strchr(path, '/') + 1) < 0 || open(path, O_RDONLY) <= 0)
	{
		free(path);
		return (NULL);
	}
	t = malloc(sizeof(t_texture));
	t->name = path;
	return t;
}

int 	identify_pattern(const char *pattern)
{
	int pat;
	static int perlin_status = 0;

//	TODO Проверка всего паттерна на то, что он состоиз из цифр
	if (!ft_isdigit(*pattern))
		return (0);
//	TODO Что будет, если в атои попадёт не цифра?
	pat = ft_atoi(pattern);
	if (pat >= PERLIN_N && pat <= MARBLE && perlin_status++ == 0)
		init_noise();
	return (pat);
}

void	parse_material_description(t_scene *scene, char *property, char *value)
{
	int i;

	i = scene->act_mat;
	if (!(ft_strcmp(property, FILE_MATERIAL_NAME)))
		scene->mats.arr[i]->name = ft_strdup(value);
	else if (!(ft_strcmp(property, FILE_MATERIAL_COLOR)))
		scene->mats.arr[i]->color = parse_color(value);
	else if (!(ft_strcmp(property, FILE_MATERIAL_SPECULAR)))
		scene->mats.arr[i]->spec = ft_atoi(value);
	else if (!(ft_strcmp(property, FILE_MATERIAL_REFLECTIVE)))
		scene->mats.arr[i]->refl = (double)ft_atoi(value) / 10.0;
	else if (!(ft_strcmp(property, FILE_MATERIAL_TEXTURE)))
		scene->mats.arr[i]->t = identify_texture(value);
	else if (!(ft_strcmp(property, FILE_MATERIAL_PATTERN)))
		scene->mats.arr[i]->pattern = identify_pattern(value);
	else
		put_error_wrong_scene_data(property, "wrong material property name");
}

void	parse_object_description(t_scene *scene, char *property, char *value)
{
	int i;

	i = scene->act_obj;
	scene->objs.arr[i]->id = i;
	if (!(ft_strcmp(property, FILE_OBJECT_TYPE)))
		scene->objs.arr[i]->type = find_object_type(value);
	else if (!(ft_strcmp(property, FILE_OBJECT_MATERIAL)))
		scene->objs.arr[i]->mat = find_object_material(scene, value);
	else if (!(ft_strcmp(property, FILE_OBJECT_POSITION)))
		scene->objs.arr[i]->pos = parse_vector(value);
	else if (!(ft_strcmp(property, FILE_OBJECT_ORIENTATION)))
		scene->objs.arr[i]->dir = parse_vector(value);
	else if (!(ft_strcmp(property, FILE_OBJECT_RADIUS)))
		scene->objs.arr[i]->radius = ft_atoi(value);
	else
		put_error_wrong_scene_data(property, "wrong object property name");
}

int		find_object_type(char *value)
{
	if (!(ft_strcmp(value, FILE_OBJECT_TYPE_PLANE)))
		return (OBJECT_TYPE_PLANE);
	else if (!(ft_strcmp(value, FILE_OBJECT_TYPE_SPHERE)))
		return (OBJECT_TYPE_SPHERE);
	else if (!(ft_strcmp(value, FILE_OBJECT_TYPE_CYLINDER)))
		return (OBJECT_TYPE_CYLINDER);
	else if (!(ft_strcmp(value, FILE_OBJECT_TYPE_CONE)))
		return (OBJECT_TYPE_CONE);
	put_error_wrong_scene_data(value, "wrong object type");
	return (-1);
}

int		find_object_material(t_scene *scene, char *value)
{
	int	i;

	i = -1;
	while (++i < scene->mats.quant - 1)
	{
		if (!(ft_strcmp(scene->mats.arr[i]->name, value)))
			return (i);
	}
	put_error_wrong_scene_data(value, "wrong object material name");
	return (-1);
}

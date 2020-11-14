/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:09:36 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/14 06:30:54 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/rt.h"

void	parse_material_descript_1(t_scene *scene, char *property, char *value)
{
	int i;

	i = scene->act_mat;
	if (!(ft_strcmp(property, FILE_MATERIAL_NAME)))
		scene->mats.arr[i]->name = ft_strdup(value);
	else if (!(ft_strcmp(property, FILE_MATERIAL_COLOR)))
		scene->mats.arr[i]->color = parse_color(value);
	else if (!(ft_strcmp(property, FILE_MATERIAL_SPECULAR)))
		scene->mats.arr[i]->spec = validate(value, 0, 1024);
	else if (!(ft_strcmp(property, FILE_MATERIAL_REFLECTIVE)))
		scene->mats.arr[i]->refl = (double)validate(value, 0, 1024) / 10.0;
	else if (!(ft_strcmp(property, FILE_MATERIAL_TRANSPARENCY)))
		scene->mats.arr[i]->transp = (double)validate(value, 0, 1000) / 10.0;
	else
		parse_material_descript_2(scene, property, value);
}

void	parse_material_descript_2(t_scene *scene, char *property, char *value)
{
	int i;

	i = scene->act_mat;
	if (!(ft_strcmp(property, FILE_MATERIAL_REFRACTIVE)))
		scene->mats.arr[i]->refr = (double)validate(value, 0, 100) / 10.0;
	else if (!(ft_strcmp(property, FILE_MATERIAL_TEXTURE)))
		scene->mats.arr[i]->t = identify_texture(value);
	else if (!(ft_strcmp(property, FILE_MATERIAL_PATTERN)))
		scene->mats.arr[i]->pattern = identify_pattern(value);
	else if (!(ft_strcmp(property, FILE_MATERIAL_SCALE)))
		scene->mats.arr[i]->scale = validate(value, 1, 100);
	else if (!(ft_strcmp(property, FILE_MATERIAL_SHIFT)))
		scene->mats.arr[i]->shift = parse_vector(value);
	else if (!(ft_strcmp(property, FILE_MATERIAL_ANGLE)))
		scene->mats.arr[i]->angle = 1 - (double)validate(value, 0, 450) / 10.0;
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
	else if (!(ft_strcmp(property, FILE_OBJECT_GROUP)))
		scene->objs.arr[i]->group = validate(value, 0, 99);
	else if (!(ft_strcmp(property, FILE_OBJECT_MATERIAL)))
		scene->objs.arr[i]->mat_name = ft_strdup(value);
	else if (!(ft_strcmp(property, FILE_OBJECT_POSITION)))
		scene->objs.arr[i]->pos = parse_vector(value);
	else if (!(ft_strcmp(property, FILE_OBJECT_ORIENTATION)))
		scene->objs.arr[i]->dir = nrm(parse_vector(value));
	else if (!(ft_strcmp(property, FILE_OBJECT_RADIUS)))
		scene->objs.arr[i]->radius = validate(value, 1, 1000);
	else if (!(ft_strcmp(property, FILE_OBJECT_LENGTH)))
		scene->objs.arr[i]->len = (double)validate(value, 1, 1000) / 10;
	else if (!(ft_strcmp(property, FILE_OBJECT_NEGATIVE)))
		scene->objs.arr[i]->neg = (validate(value, -1, 1) > 0) ? 1 : 0;
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
	else if (!(ft_strcmp(value, FILE_OBJECT_TYPE_PARABOLOID)))
		return (OBJECT_TYPE_PARABOLOID);
	else if (!(ft_strcmp(value, FILE_OBJECT_TYPE_HYPERBOLOID)))
		return (OBJECT_TYPE_HYPERBOLOID);
	put_error_wrong_scene_data(value, "wrong object type");
	return (-1);
}

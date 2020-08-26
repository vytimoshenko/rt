/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:09:03 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:09:05 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

int		count_items_by_type(t_scene *scene, char *item_line)
{
	int		i;
	char	*type;

	if ((i = ft_strindex('{', item_line)) < 0)
		put_error_wrong_scene_data(item_line, "missing '{'");
	type = ft_strnew(i);
	ft_strncpy(type, item_line, i);
	define_item_type(scene, type);
	ft_strdel(&type);
	return (0);
}

int		define_item_type(t_scene *scene, char *type)
{
	if (!(ft_strcmp(type, FILE_SCENE)))
		return (FILE_PARSE_SCENE);
	else if (!(ft_strcmp(type, FILE_CAMERA)))
	{
		scene->act_cam++;
		return (FILE_PARSE_CAMERA);
	}
	else if (!(ft_strcmp(type, FILE_LIGHT)))
	{
		scene->act_light++;
		return (FILE_PARSE_LIGHT);
	}
	else if (!(ft_strcmp(type, FILE_MATERIAL)))
	{
		scene->act_mat++;
		return (FILE_PARSE_MATERIAL);
	}
	else if (!(ft_strcmp(type, FILE_OBJECT)))
	{
		scene->act_obj++;
		return (FILE_PARSE_OBJECT);
	}
	else
		put_error_wrong_scene_data(type, "wrong item type name");
	return (0);
}

void	put_error_wrong_scene_data(char *wrong_data, char *message)
{
	ft_putstr("=> ");
	ft_putendl(wrong_data);
	put_error_pn(message);
}

void	save_quantities(t_scene *scene)
{
	scene->cams.quant = scene->act_cam;
	if (scene->cams.quant == 0)
		put_error_pn("scene file must contain at least one camera");
	scene->lights.quant = scene->act_light;
	if (scene->lights.quant == 0)
		put_error_pn("scene file must contain at least one light");
	scene->mats.quant = scene->act_mat;
	if (scene->mats.quant == 0)
		put_error_pn("scene file must contain at least one material");
	scene->objs.quant = scene->act_obj;
	if (scene->objs.quant == 0)
		put_error_pn("scene file must contain at least one object");
	scene->act_cam = NOTHING_SELECTED;
	scene->act_light = NOTHING_SELECTED;
	scene->act_mat = NOTHING_SELECTED;
	scene->act_obj = NOTHING_SELECTED;
}

void	allocate_memory(t_scene *scene)
{
	int	i;

	scene->cams.arr = (t_cam **)ft_memalloc(sizeof(t_cam *) *
	scene->cams.quant);
	i = -1;
	while (++i < scene->cams.quant)
		scene->cams.arr[i] = (t_cam *)ft_memalloc(sizeof(t_cam));
	scene->lights.arr = (t_light **)ft_memalloc(sizeof(t_light *) *
	scene->lights.quant);
	i = -1;
	while (++i < scene->lights.quant)
		scene->lights.arr[i] = (t_light *)ft_memalloc(sizeof(t_light));
	scene->mats.arr = (t_mat **)ft_memalloc(sizeof(t_mat *) *
	scene->mats.quant);
	i = -1;
	while (++i < scene->mats.quant)
		scene->mats.arr[i] =
		(t_mat *)ft_memalloc(sizeof(t_mat));
	scene->objs.arr = (t_obj **)ft_memalloc(sizeof(t_obj *) *
	scene->objs.quant);
	i = -1;
	while (++i < scene->objs.quant)
		scene->objs.arr[i] = (t_obj *)ft_memalloc(sizeof(t_obj));
}

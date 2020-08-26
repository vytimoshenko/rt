/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:09:13 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:09:15 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

int		parse_item_line(t_scene *scene, char *item_line)
{
	int		i;
	int		type_id;
	char	*type;
	char	*description;

	if ((i = ft_strindex('{', item_line)) < 0)
		put_error_wrong_scene_data(item_line, "missing '{'");
	type = ft_strnew(i);
	ft_strncpy(type, item_line, i);
	type_id = define_item_type(scene, type);
	while (--i >= -1)
		item_line++;
	if ((i = ft_strindex('}', item_line)) < 0)
		put_error_wrong_scene_data(item_line, "missing '}'");
	description = ft_strnew(i);
	ft_strncpy(description, item_line, i);
	parse_item_description(scene, type_id, description);
	ft_strdel(&type);
	ft_strdel(&description);
	return (0);
}

int		parse_item_description(t_scene *scene, int type_id, char *description)
{
	int		i;
	char	*property;
	char	*value;
	char	*prepared_value;

	if (!(*description))
		return (0);
	if ((i = ft_strindex(':', description)) < 0)
		put_error_wrong_scene_data(description, "missing ':'");
	property = ft_strnew(i);
	ft_strncpy(property, description, i);
	while (--i >= -1)
		description++;
	i = ft_strindex(';', description);
	value = ft_strnew(i);
	ft_strncpy(value, description, i);
	prepared_value = prepare_value_to_write(value);
	parse_item_by_property(scene, type_id, property, prepared_value);
	str_free(&property, &value, &prepared_value);
	while (--i >= -1)
		description++;
	if (parse_item_description(scene, type_id, description) == -1)
		return (-1);
	return (0);
}

char	*prepare_value_to_write(char *value)
{
	int		len;
	char	*prepared_value;

	if (*value == '"')
		any_whitespace_to_space(value);
	if (*value == '"' || *value == '<' || *value == '[')
	{
		value++;
		len = ft_strlen(value);
		prepared_value = ft_strnew(len - 1);
		ft_strncpy(prepared_value, value, len - 1);
	}
	else
		prepared_value = ft_strdup(value);
	return (prepared_value);
}

char	*any_whitespace_to_space(char *value)
{
	int	i;

	i = 0;
	while (value[i++] != '\0')
	{
		if (is_whitespace(value[i]))
			value[i] = ' ';
	}
	return (value);
}

void	str_free(char **property, char **value, char **prepared_value)
{
	ft_strdel(property);
	ft_strdel(value);
	ft_strdel(prepared_value);
}

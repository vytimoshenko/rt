/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:09:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/14 00:36:24 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

t_vec	parse_vector(char *value)
{
	int		i;
	char	*tmp;
	char	*value_start;
	t_vec	vector;

	value_start = value;
	tmp = ft_strnew(10);
	if ((i = ft_strindex(',', value)) < 0)
		put_error_wrong_scene_data(value_start, "missing ','");
	tmp = ft_strncat(tmp, value, i);
	vector.x = parse_number(tmp);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	if ((i = ft_strindex(',', value)) < 0)
		put_error_wrong_scene_data(value_start, "missing ','");
	tmp = ft_strncat(tmp, value, i);
	vector.y = parse_number(tmp);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	vector.z = parse_number(value);
	ft_strdel(&tmp);
	return (vector);
}

t_clr	parse_color(char *value)
{
	int		i;
	char	*tmp;
	char	*value_start;
	t_vec	color;

	value_start = value;
	tmp = ft_strnew(10);
	if ((i = ft_strindex(',', value)) < 0)
		put_error_wrong_scene_data(value_start, "missing ','");
	tmp = ft_strncat(tmp, value, i);
	color.x = parse_number(tmp);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	if ((i = ft_strindex(',', value)) < 0)
		put_error_wrong_scene_data(value_start, "missing ','");
	tmp = ft_strncat(tmp, value, i);
	color.y = parse_number(tmp);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	color.z = parse_number(value);
	ft_strdel(&tmp);
	validate_color(value_start, color);
	return ((t_clr){color.x, color.y, color.z});
}

void	validate_color(char *value, t_vec color)
{
	if (color.x > 255 || color.y > 255 || color.z > 255 ||
	color.x < 0 || color.y < 0 || color.z < 0)
		put_error_wrong_scene_data(value, "wrong color in scene");
}

int		parse_number(char *str)
{
	char	*value;
	int		i;
	int		num;

	value = delete_whitespaces(str);
	if (ft_strlen(value) == 0)
		put_error_wrong_scene_data(str, "no value");
	i = 0;
	while (value[i] != '\0')
	{
		if (ft_isdigit(value[i]) || value[i] == '-')
			i++;
		else
			put_error_wrong_scene_data(str, "invalid value");
	}
	num = ft_atoi(value);
	if (num == 0 && value[0] != '0')
		put_error_wrong_scene_data(str, "invalid value");
	free(value);
	return (num);
}

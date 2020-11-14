/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:09:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/14 02:51:02 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/rt.h"

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
	vector.x = validate(tmp, -1024, 1024);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	if ((i = ft_strindex(',', value)) < 0)
		put_error_wrong_scene_data(value_start, "missing ','");
	tmp = ft_strncat(tmp, value, i);
	vector.y = validate(tmp, -1024, 1024);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	vector.z = validate(value, -1024, 1024);
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
	color.x = validate(tmp, 0, 255);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	if ((i = ft_strindex(',', value)) < 0)
		put_error_wrong_scene_data(value_start, "missing ','");
	tmp = ft_strncat(tmp, value, i);
	color.y = validate(tmp, 0, 255);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	color.z = validate(value, 0, 255);
	ft_strdel(&tmp);
	return ((t_clr){color.x, color.y, color.z});
}

int		parse_number(char *str)
{
	int		i;
	int		num;

	if (ft_strlen(str) == 0)
		put_error_wrong_scene_data(str, "no value");
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) || str[i] == '-')
			i++;
		else
			put_error_wrong_scene_data(str, "invalid value");
	}
	num = ft_atoi(str);
	if (num == 0 && str[0] != '0')
		put_error_wrong_scene_data(str, "invalid value");
	return (num);
}

int		validate(char *str, int min, int max)
{
	int		num;
	char	*limit;
	char	*message;

	num = parse_number(str);
	if (num < min)
	{
		limit = ft_itoa(min);
		message = ft_strjoin("value is too small, must be bigger than: ",
		limit);
		free(limit);
		put_error_wrong_scene_data(str, message);
	}
	if (num > max)
	{
		limit = ft_itoa(max);
		message = ft_strjoin("value is too big, must be less than: ", limit);
		free(limit);
		put_error_wrong_scene_data(str, message);
	}
	return (num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_8_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 21:11:08 by wquirrel          #+#    #+#             */
/*   Updated: 2020/10/30 20:49:05 by wquirrel         ###   ########.fr       */
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_save_screenshot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:54:47 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/09 19:44:25 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	save_screenshot(t_scene *scene, t_mlx *mlx)
{
	char		*file_name;
	SDL_Surface	*surface;

	file_name = NULL;
	create_screenshot_file_name(scene, &file_name);
	surface = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING))
		put_error_pn("SDL_Init");
	if (!(surface = SDL_CreateRGBSurfaceFrom(mlx->data, IMG_SIZE_W, IMG_SIZE_H,
	32, sizeof(int) * IMG_SIZE_W, 0, 0, 0, 0)))
		put_error_pn("SDL_CreateRGBSurfaceFrom");
	if (IMG_SavePNG(surface, file_name))
		put_error_pn("IMG_SavePNG");
	SDL_FreeSurface(surface);
	info_message_box(mlx, SCREENSHOT_MESSAGE_TITLE, file_name);
	free(file_name);
}

void	create_screenshot_file_name(t_scene *scene, char **file_name)
{
	int		i;
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;
	char	time_string[CURRENT_TIME_STR_LENGTH];

	tmp1 = ft_strdup(scene->name);
	i = 0;
	while (tmp1[i++])
		tmp1[i] = tmp1[i] == ' ' ? '_' : tmp1[i];
	get_current_time_string(time_string);
	tmp2 = ft_strjoin(time_string, SCREENSHOT_FILE_EXTENSION);
	tmp3 = ft_strjoin(tmp1, tmp2);
	*file_name = ft_strjoin(SCREENSHOT_PATH, tmp3);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	ft_strdel(&tmp3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_save_scene_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:09:52 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:09:54 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	save_scene(t_scene *scene, t_mlx *mlx)
{
	int		fd;
	char	*file_name;

	file_name = NULL;
	create_save_file_name(scene, &file_name);
	if (!(fd = open(file_name, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP
	| S_IWGRP | S_IROTH | S_IWOTH)))
		ft_put_errno(PROGRAM_NAME);
	write_all_info(scene, fd);
	close(fd);
	info_message_box(mlx, SAVE_MESSAGE_TITLE, file_name);
	free(file_name);
}

void	create_save_file_name(t_scene *scene, char **file_name)
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
	tmp2 = ft_strjoin(time_string, SCENE_FILE_EXTENSION);
	tmp3 = ft_strjoin(tmp1, tmp2);
	*file_name = ft_strjoin(SAVE_PATH, tmp3);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	ft_strdel(&tmp3);
}

void	get_current_time_string(char *time_string)
{
	time_t		current_time;
	struct tm	*time_info;
	int			i;

	time(&current_time);
	time_info = localtime(&current_time);
	strftime(time_string, CURRENT_TIME_STR_LENGTH, "_%F_%T", time_info);
	i = 0;
	while (time_string[i++])
		time_string[i] = time_string[i] == ':' ? '-' : time_string[i];
}

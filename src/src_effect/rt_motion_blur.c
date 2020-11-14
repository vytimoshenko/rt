/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_motion_blur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:20:48 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/14 05:58:01 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/rt.h"

void	make_motion_blur(t_global *global)
{
	int	n;
	int	i;

	global->scene->ready_for_motion = false;
	n = -1;
	while (++n < MOTION_BLUR_BUFFERS)
	{
		show_progress_bar(global->mlx, n + 1);
		global->scene->in_motion = true;
		move_object(global, global->scene->move_direction);
		run_pthreads(global->scene);
		i = -1;
		while (++i < IMG_SIZE_W * IMG_SIZE_H)
			global->scene->motion_blur_buffs[n][i] =
			global->scene->pix_buff[i].color;
	}
	show_progress_bar(global->mlx, MOTION_BLUR_BUFFERS);
	merge_buffers(global->scene->pix_buff, global->scene->motion_blur_buffs);
	if (MOTION_BLUR_OVERLAY_FINAL_POS)
		overlay_final_object_position(global->scene);
	global->scene->in_motion = false;
	global->scene->finished_motion = true;
	update_interface_and_frame(global);
}

void	merge_buffers(t_pix *pix_buff, t_clr **motion_blur_buffs)
{
	int i;
	int n;
	int sum_r;
	int sum_g;
	int sum_b;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		sum_r = 0;
		sum_g = 0;
		sum_b = 0;
		n = -1;
		while (++n < MOTION_BLUR_BUFFERS)
		{
			sum_r += motion_blur_buffs[n][i].r;
			sum_g += motion_blur_buffs[n][i].g;
			sum_b += motion_blur_buffs[n][i].b;
		}
		pix_buff[i].color.r = (int)(sum_r / MOTION_BLUR_BUFFERS);
		pix_buff[i].color.g = (int)(sum_g / MOTION_BLUR_BUFFERS);
		pix_buff[i].color.b = (int)(sum_b / MOTION_BLUR_BUFFERS);
	}
}

void	overlay_final_object_position(t_scene *scene)
{
	int i;
	int group;

	group = scene->objs.arr[scene->act_obj]->group;
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		if ((group == NO_GROUP && scene->pix_buff[i].obj_id == scene->act_obj)
		|| (scene->pix_buff[i].obj_id != NOTHING_SELECTED &&
		scene->objs.arr[scene->pix_buff[i].obj_id]->group == group))
			scene->pix_buff[i].color =
			scene->motion_blur_buffs[MOTION_BLUR_BUFFERS - 1][i];
	}
}

void	show_last_frame(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->pix_buff[i].color =
		scene->motion_blur_buffs[MOTION_BLUR_BUFFERS - 1][i];
}

void	show_progress_bar(t_mlx *mlx, int n)
{
	char	*str;
	char	*tmp1;
	char	*tmp2;
	double	progress;

	str = ft_itoa(n);
	tmp1 = ft_strjoin("Rendering frame #", str);
	free(str);
	tmp2 = ft_strjoin(tmp1, " out of ");
	free(tmp1);
	tmp1 = ft_itoa(MOTION_BLUR_BUFFERS);
	str = ft_strjoin(tmp2, tmp1);
	free(tmp1);
	free(tmp2);
	progress = (n - 1) / (double)MOTION_BLUR_BUFFERS;
	info_message_box_bar(mlx, MOTION_BLUR_TITLE, str, progress);
	free(str);
}

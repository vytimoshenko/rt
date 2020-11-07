/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prepare_buffers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:10 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/07 09:07:41 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	prepare_buffers(t_scene *scene)
{
	int	i;

	if (!(scene->pix_buff = (t_pix *)ft_memalloc(sizeof(t_pix) *
	(IMG_SIZE_W * IMG_SIZE_H))))
		ft_put_errno(PROGRAM_NAME);
	if (!(scene->motion_blur_buffs = (t_clr **)ft_memalloc(sizeof(t_clr *) *
	MOTION_BLUR_BUFFERS)))
		ft_put_errno(PROGRAM_NAME);
	i = -1;
	while (++i < MOTION_BLUR_BUFFERS) {
		if (!(scene->motion_blur_buffs[i] = (t_clr *)ft_memalloc(sizeof(t_clr) *
		(IMG_SIZE_W * IMG_SIZE_H))))
			ft_put_errno(PROGRAM_NAME);
	}
}

void	clean_pix_buffer(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		scene->pix_buff[i].obj_id = EMPTY;
		ft_memset(&scene->pix_buff[i].color, 0, sizeof(t_clr));
	}
}

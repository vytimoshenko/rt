/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_clean_pix_buffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:10 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:10:11 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	clean_pix_buffer(t_peace *p)
{
	int	i;

	i = IMG_SIZE_W * IMG_SIZE_H / PEACES * p->i - 1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H / PEACES * (p->i + 1))
	{
		p->scene->pix_buff[i].obj_id = EMPTY;
		ft_memset(&p->scene->pix_buff[i].color, 0, sizeof(t_clr));
	}
}

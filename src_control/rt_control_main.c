/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:06:00 by mperseus          #+#    #+#             */
/*   Updated: 2020/10/30 22:47:46 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	loop(t_global *global)
{
	mlx_hook(global->mlx->win, 2, 0, keyboard_key_press, global);
	mlx_hook(global->mlx->win, 4, 0, mouse_key_press, global);
	mlx_hook(global->mlx->win, 5, 0, mouse_key_release, global);
	mlx_hook(global->mlx->win, 6, 0, mouse_move, global);
	mlx_hook(global->mlx->win, 17, 0, close_window, global);
	mlx_loop(global->mlx->mlx);
}

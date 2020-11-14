/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:15 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/14 06:04:04 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/rt.h"

int	main(int argc, char **argv)
{
	t_global	global;

	global.scene = init_scene(argc, argv);
	global.mlx = init_mlx();
	get_textures(&global);
	draw(&global);
	loop(&global);
	exit(0);
}

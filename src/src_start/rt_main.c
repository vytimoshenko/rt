/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:15 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/14 16:31:12 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/rt.h"

int	main(int argc, char **argv)
{
	t_global	global;

	global.scene = init_scene(argc, argv);
	global.mlx = init_mlx();
	if (SDL_Init(SDL_INIT_EVERYTHING))
		put_error_pn("SDL_Init");
	get_textures(&global);
	draw(&global);
	loop(&global);
	exit(0);
}

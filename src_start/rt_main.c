/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:15 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:10:17 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

int	main(int argc, char **argv)
{
	t_global	global;

	global.scene = init_scene(argc, argv);
	init_sdl(&(global.sdl));
	draw(&global);
	loop(&global);
	SDL_DestroyRenderer(global.sdl.render);
	SDL_DestroyWindow(global.sdl.window);
	SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
	SDL_Quit();
	return (0);
}

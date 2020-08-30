/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_start_mlx_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:29 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:12:41 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_GetError();
	sdl->window = SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED
			, SDL_WINDOWPOS_UNDEFINED, WIN_SIZE_W,  WIN_SIZE_H, SDL_WINDOW_SHOWN);
	sdl->render = SDL_CreateRenderer(sdl->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderClear(sdl->render);
}

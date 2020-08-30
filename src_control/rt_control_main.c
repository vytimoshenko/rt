/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_control_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:06:00 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:06:02 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	loop(t_global *global)
{
	int run;
	SDL_Event	event;

	(void)global;
	run = 1;
	while (run)
	{
		while (SDL_WaitEvent(&event) && run)
		{
			if (event.type == SDL_QUIT)
				run = 0;
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					run = 0;
			}
		}
	}
}

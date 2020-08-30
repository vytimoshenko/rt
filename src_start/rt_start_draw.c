/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_start_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:24 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:10:26 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rt.h"

void	draw(t_global *global)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	SDL_RenderClear(global->sdl.render);
	trace_rays(global->scene);
	final_processing(&(*global).sdl, global->scene);
	SDL_RenderPresent(global->sdl.render);
	gettimeofday(&end, NULL);
	// count_frames(global->mlx, start, end);
	// show_interface(global);
}

void	count_frames(t_mlx *mlx, struct timeval start, struct timeval end)
{
	++mlx->frames;
	mlx->frame_time = (double)(end.tv_usec - start.tv_usec) / 1000 +
	(double)(end.tv_sec - start.tv_sec) * 1000;
}

void	update_interface_only(t_global *global)
{
	SDL_RenderClear(global->sdl.render);
	SDL_RenderPresent(global->sdl.render);
	// show_interface(global);
}

void	update_interface_and_frame(t_global *global)
{
	SDL_RenderClear(global->sdl.render);
	final_processing(&(*global).sdl, global->scene);
	SDL_RenderPresent(global->sdl.render);
	// show_interface(global);
}

void	put_error_pn(char *str)
{
	ft_putstr(PROGRAM_NAME);
	ft_putstr(": ");
	ft_putendl(str);
	exit(1);
}

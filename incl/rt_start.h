/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_start.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:04:22 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:04:24 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef rt_START_H

# define rt_START_H

# define FALSE	0
# define TRUE	1

int			main(int argc, char **argv);

t_scene		*init_scene(int argc, char **argv);
void		set_initial_status(t_scene *scene);
void		get_lights_statistics(t_scene *scene);
void		get_objects_statistics(t_scene *scene);
void		set_initial_angles(t_scene *scene);

t_mlx		*init_mlx(void);
void		init_sdl(t_sdl *sdl);
void		clean_mlx(t_mlx *mlx);
void		put_mlx_error(t_mlx *mlx, char *str);

void		clean_pix_buffer(t_scene *scene);

void		draw(t_global *global);
void		count_frames(t_mlx *mlx, struct timeval start, struct timeval end);
void		update_interface_only(t_global *global);
void		update_interface_and_frame(t_global *global);
void		put_error_pn(char *str);

#endif

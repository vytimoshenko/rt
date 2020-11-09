/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:03:05 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/09 20:03:25 by mperseus         ###   ########.fr       */
/*   Updated: 2020/11/08 00:03:53 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H

# define RT_H

# include "../libft/libft.h"
//# include "../lib/mlx.h"
//# include "../minilibx_mms_20200219/mlx.h"
# include "../SDL2/headers/SDL.h"
# include "../SDL2/headers/SDL_image.h"
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>

# include "../mlx/mlx.h"
# include <time.h>
# include "../SDL2/headers/SDL.h"
# include "../SDL2/headers/SDL_image.h"

# include <math.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

# include "rt_structures.h"
# include "rt_trace.h"
# include "rt_start.h"
# include "rt_read_save.h"
# include "rt_effect.h"
# include "rt_control.h"
# include "rt_interface.h"
# include "rt_textures.h"

# include <stdio.h>

# define PROGRAM_NAME	"rt"

#endif

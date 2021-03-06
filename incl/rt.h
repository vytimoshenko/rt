/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:03:05 by mperseus          #+#    #+#             */
/*   Updated: 2020/11/12 21:13:48 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H

# define RT_H

# include "../libft/libft.h"

# include "../mlx/mlx.h"
# include "../frameworks/SDL2/SDL.h"
# include "../frameworks/SDL2/SDL_image.h"

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

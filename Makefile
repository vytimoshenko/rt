# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 19:45:56 by hlorrine          #+#    #+#              #
#    Updated: 2020/11/14 12:46:03 by wquirrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	RT

HDR		= 	./incl 	\
			-I./frameworks/SDL2.framework/Versions/A/Headers \
            -I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
            -I./frameworks/SDL2_image.framework/Versions/A/Headers \
            -I./frameworks/SDL2_mixer.framework/Headers \
            -F./frameworks/


SRC		=	src/src_control/rt_control_camera.c         \
            src/src_control/rt_control_effect.c         \
            src/src_control/rt_control_hooks.c          \
            src/src_control/rt_control_interface.c      \
            src/src_control/rt_control_keyboard_1.c     \
            src/src_control/rt_control_keyboard_2.c     \
            src/src_control/rt_control_light.c          \
            src/src_control/rt_control_main.c           \
            src/src_control/rt_control_material.c       \
            src/src_control/rt_control_object.c         \
            src/src_control/rt_control_reset.c          \
            src/src_effect/rt_effect_antialias_1.c      \
            src/src_effect/rt_effect_antialias_2.c      \
            src/src_effect/rt_effect_color_1.c          \
            src/src_effect/rt_effect_color_2.c          \
            src/src_effect/rt_effect_color_3.c          \
            src/src_effect/rt_effect_main.c             \
            src/src_effect/rt_effect_other.c            \
            src/src_effect/rt_effect_pixelation.c       \
            src/src_effect/rt_motion_blur.c             \
            src/src_interface/rt_interface_bottom.c     \
            src/src_interface/rt_interface_camera.c     \
            src/src_interface/rt_interface_effect.c     \
            src/src_interface/rt_interface_help_1.c     \
            src/src_interface/rt_interface_help_2.c     \
            src/src_interface/rt_interface_light.c      \
            src/src_interface/rt_interface_main.c       \
            src/src_interface/rt_interface_material_1.c \
            src/src_interface/rt_interface_material_2.c \
            src/src_interface/rt_interface_object.c     \
            src/src_interface/rt_interface_other.c      \
            src/src_interface/rt_interface_render.c     \
            src/src_interface/rt_interface_scene_1.c    \
            src/src_interface/rt_interface_scene_2.c    \
            src/src_read_save/rt_read_scene_1.c         \
            src/src_read_save/rt_read_scene_2.c         \
            src/src_read_save/rt_read_scene_3.c         \
            src/src_read_save/rt_read_scene_4.c         \
            src/src_read_save/rt_read_scene_5.c         \
            src/src_read_save/rt_read_scene_6.c         \
            src/src_read_save/rt_read_scene_7.c         \
            src/src_read_save/rt_read_scene_8.c         \
            src/src_read_save/rt_read_scene_9.c         \
            src/src_read_save/rt_save_scene_1.c         \
            src/src_read_save/rt_save_scene_2.c         \
            src/src_read_save/rt_save_scene_3.c         \
            src/src_read_save/rt_save_screenshot.c      \
            src/src_start/rt_main.c                     \
            src/src_start/rt_prepare_buffers.c          \
            src/src_start/rt_start_draw.c               \
            src/src_start/rt_start_mlx_init.c           \
            src/src_start/rt_start_scene_init.c         \
            src/src_texture/rt_texture_noise.c          \
            src/src_texture/texture_main.c              \
            src/src_texture/texture_noises.c            \
            src/src_texture/texture_procedural.c        \
            src/src_texture/texture_utils1.c            \
            src/src_texture/texture_utils2.c            \
            src/src_texture/uv_mapping1.c               \
            src/src_texture/uv_mapping2.c               \
            src/src_trace/rt_trace_core.c               \
            src/src_trace/rt_trace_intersect_1.c        \
            src/src_trace/rt_trace_intersect_2.c        \
            src/src_trace/rt_trace_intersect_3.c        \
            src/src_trace/rt_trace_light_1.c            \
            src/src_trace/rt_trace_light_2.c            \
            src/src_trace/rt_trace_main.c               \
            src/src_trace/rt_trace_normals_1.c          \
            src/src_trace/rt_trace_normals_2.c          \
            src/src_trace/rt_trace_pthreads.c           \
            src/src_trace/rt_trace_vector_1.c           \
            src/src_trace/rt_trace_vector_2.c

OBJ		= 	$(SRC:.c=.o)

CMPLR	=	gcc

MK_FT	=	make			-C libft
CL_FT	=	make clean		-C libft
FCL_FT	=	make fclean		-C libft

MK_MLX	=	make			-C mlx
CL_MLX	=	make clean		-C mlx
CP_MLX  =	cp ./mlx/libmlx.dylib ./
RM_MLX  =	rm -rf ./libmlx.dylib

MK_DIR	=	@/bin/mkdir -p saves screenshots

ADD_ERR =	-Wall -Wextra -Werror
ADD_DEP =	-Wno-deprecated-declarations

ADD_OPT =	-Ofast

ADD_LIB =	-L ./libft	-l ft	\
			-L ./mlx	-l mlx	\
#			-L ./SDL2/SDL2 			-l SDL2			\
#			-L ./SDL2/SDL2_image	-l SDL2_image

MLX		=	libmlx.dylib

ADD_FMW =	-Lmlx -lmlx -framework OpenGL -framework AppKit -lm \
			-framework SDL2_ttf -framework SDL2_image -framework SDL2_mixer \
			-framework SDL2 -rpath ./frameworks \


OBJDIR	=	./obj/
OBJ		=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

all:		$(NAME)

$(NAME):	obj $(OBJ)
			@$(MK_FT)
			@$(MK_MLX)
			@$(CP_MLX)
			@$(CMPLR) -o $(NAME) -I $(HDR) $(SRC) $(ADD_ERR) $(ADD_OPT) $(ADD_LIB) $(ADD_FMW) $(ADD_DEP)
			@echo "\033[32m- RT compiled\033[0m"
			@$(MK_DIR)

obj:
			@mkdir -p $(OBJDIR)
			@mkdir -p $(dir $(OBJ))

$(OBJDIR)%.o:		%.c	./incl/*.h
			$(CMPLR) $< -c -o $@

clean:
			@/bin/rm -f $(OBJ)
			@/bin/rm -rf obj
			$(CL_FT)
			$(CL_MLX)
			@/bin/rm -rf saves screenshots
			@echo "\033[31m- RT object files removed\033[0m"

fclean: 	clean
			@/bin/rm -f $(NAME)
			$(FCL_FT)
			$(RM_MLX)
			@echo "\033[31m- RT removed\033[0m"

re: 		fclean all

.PHONY: 	all clean fclean re

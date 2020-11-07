cmake_minimum_required(VERSION 3.17)
project(RT C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-Wextra -Wall -Werror")

set(CMAKE_SKIP_RPATH TRUE)

#include_directories(.)
include_directories(incl)
include_directories(libft)
include_directories(mlx)
#include_directories(mlx)

add_executable(RT
        libft/ft_arrdel.c
        libft/ft_arrfill.c
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_find_eol.c
        libft/ft_intlen.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_lstadd.c
        libft/ft_lstdel.c
        libft/ft_lstdelmy.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_ltrcnt.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_power.c
        libft/ft_put_errno.c
        libft/ft_put_error.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_strindex.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/ft_wrdcnt.c
        libft/get_next_line.c
        libft/libft.h
        src_control/rt_control_camera.c
        src_control/rt_control_effect.c
        src_control/rt_control_hooks.c
        src_control/rt_control_interface.c
        src_control/rt_control_keyboard_1.c
        src_control/rt_control_keyboard_2.c
        src_control/rt_control_light.c
        src_control/rt_control_main.c
        src_control/rt_control_material.c
        src_control/rt_control_object.c
        src_control/rt_control_reset.c
        src_effect/rt_effect_antialias_1.c
        src_effect/rt_effect_antialias_2.c
        src_effect/rt_effect_color_1.c
        src_effect/rt_effect_color_2.c
        src_effect/rt_effect_color_3.c
        src_effect/rt_effect_main.c
        src_effect/rt_effect_other.c
        src_effect/rt_effect_pixelation.c
        src_interface/rt_interface_bottom.c
        src_interface/rt_interface_camera.c
        src_interface/rt_interface_effect.c
        src_interface/rt_interface_help_1.c
        src_interface/rt_interface_help_2.c
        src_interface/rt_interface_light.c
        src_interface/rt_interface_main.c
        src_interface/rt_interface_object.c
        src_interface/rt_interface_other.c
        src_interface/rt_interface_render.c
        src_interface/rt_interface_scene.c
        src_read_save/rt_read_scene_1.c
        src_read_save/rt_read_scene_2.c
        src_read_save/rt_read_scene_3.c
        src_read_save/rt_read_scene_4.c
        src_read_save/rt_read_scene_5.c
        src_read_save/rt_read_scene_6.c
        src_read_save/rt_read_scene_7.c
        src_read_save/rt_save_scene_1.c
        src_read_save/rt_save_scene_2.c
        src_read_save/rt_save_scene_3.c
        src_start/rt_clean_pix_buffer.c
        src_start/rt_main.c
        src_start/rt_start_draw.c
        src_start/rt_start_mlx_init.c
        src_start/rt_start_scene_init.c
        src_trace/rt_trace_core.c
        src_trace/rt_trace_intersect_1.c
        src_trace/rt_trace_intersect_2.c
        src_trace/rt_trace_light.c
        src_trace/rt_trace_main.c
        src_trace/rt_trace_normals.c
        src_trace/rt_trace_vector_1.c
        src_trace/rt_trace_vector_2.c
        src_texture/texture_main.c src_texture/texture_procedural.c src_texture/uv_mapping1.c src_texture/texture_utils1.c src_texture/texture_noises.c src_read_save/rt_read_scene_8_texture.c src_texture/uv_mapping2.c src_texture/rt_texture_noise.c
        src_trace/rt_trace_added.c src_texture/texture_utils2.c
        src_interface/rt_interface_material_1.c
        src_interface/rt_interface_material_2.c)

#target_link_libraries(RT  /Users/wquirrel/Desktop/rt/mlx/libmlx.a)
#target_link_libraries(RT  "-framework AppKit" "-framework OpenGL" /Users/wquirrel/Desktop/rt/minilibx_mms_20200219/libmlx.dylib)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/mlx/libmlx.dylib)
target_link_libraries(RT "-framework OpenGL -framework AppKit")
#target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/mlx/libmlx.dylib)
#target_link_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/mlx)
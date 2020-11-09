# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 19:45:56 by hlorrine          #+#    #+#              #
#    Updated: 2020/11/04 21:01:47 by mperseus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	RT

HDR		= 	./incl

SRC		= 	$(wildcard src_start/*.c)		\
			$(wildcard src_read_save/*.c)	\
			$(wildcard src_trace/*.c)		\
			$(wildcard src_effect/*.c)		\
			$(wildcard src_control/*.c)		\
			$(wildcard src_interface/*.c)	\
			$(wildcard src_texture/*.c)

OBJ		= 	$(SRC:.c=.o)

CMPLR	=	gcc

MK_FT	=	make			-C libft
CL_FT	=	make clean		-C libft
FCL_FT	=	make fclean		-C libft

MK_MLX	=	make			-C mlx
CL_MLX	=	make clean		-C mlx

MK_DIR	=	@/bin/mkdir saves screenshots

ADD_ERR =	-Wall -Wextra -Werror
ADD_DEP =	-Wno-deprecated-declarations

ADD_OPT =	-Ofast

ADD_LIB =	-L ./libft	-l ft	\
			-L ./mlx	-l mlx	\
			-L ./SDL2/SDL2 			-l SDL2			\
			-L ./SDL2/SDL2_image	-l SDL2_image
#			-L ./minilibx_mms_20200219	-l mlx

MLX				= libmlx.dylib

ADD_FMW =	-Lmlx -lmlx -framework OpenGL -framework AppKit -lm
#ADD_FMW =	-lmlx -framework OpenGL -framework AppKit

OBJDIR	= ./obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

all:		$(NAME)

$(NAME):	obj $(OBJ)
			@$(MK_FT)
			@$(MK_MLX)
			@$(CMPLR) -o $(NAME) -I $(HDR) $(SRC) $(ADD_ERR) $(ADD_OPT) $(ADD_LIB) $(ADD_FMW) $(ADD_DEP)
			@$(MK_DIR)

obj:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(dir $(OBJ))

$(OBJDIR)%.o:		%.c
			$(CMPLR) $< -c -o $@

clean:
			@/bin/rm -f $(OBJ)
			$(CL_FT)
			$(CL_MLX)
			@/bin/rm -rf saves screenshots

fclean: 	clean
			@/bin/rm -f $(NAME)
			$(FCL_FT)

re: 		fclean all

.PHONY: 	all clean fclean re

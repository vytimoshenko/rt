# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 19:45:56 by hlorrine          #+#    #+#              #
#    Updated: 2020/08/31 11:35:37 by wquirrel         ###   ########.fr        #
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
			
OBJ		= 	$(SRC:.c=.o)

CMPLR	=	gcc

MK_FT	=	make			-C libft
CL_FT	=	make clean		-C libft
FCL_FT	=	make fclean		-C libft

MK_MLX	=	make			-C mlx-linux
CL_MLX	=	make clean		-C mlx-linux

MK_DIR	=	@/bin/mkdir saves

ADD_ERR =	-Wall -Wextra -Werror
ADD_DEP =	-Wno-deprecated-declarations

ADD_OPT =	-Ofast

ADD_LIB =	-L ./libft	-l ft	\
			-L ./mlx-linux	-l mlx -lXext -lX11 -lm

# ADD_FMW =	-lmlx -framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MK_FT)
			$(MK_MLX)
			$(CMPLR) -o $(NAME) -I $(HDR) $(SRC) $(ADD_ERR) $(ADD_OPT) $(ADD_LIB) $(ADD_DEP)
			$(MK_DIR)

%.o:		%.c
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

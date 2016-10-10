# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 01:32:20 by jpirsch           #+#    #+#              #
#    Updated: 2015/03/17 15:05:37 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../fractol
SRC		= 	main.c \
		 	draw.c \
			tree.c \
			hsv_to_rgb.c \
			hsv_to_rgb2.c \
			set_env_struct.c \
			mlx_env.c \
			control_bar.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ) -L ../libft/ -lft -L ../minilibx/ \
		-lmlx -framework OpenGL -framework AppKit

$(OBJ):
	gcc -c $(FLAGS) $(SRC) -I ../includes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

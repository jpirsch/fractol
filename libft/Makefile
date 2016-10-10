# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/13 19:48:58 by jpirsch           #+#    #+#              #
#    Updated: 2015/01/06 16:55:22 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= ft_atoi.c \
		  ft_bzero.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memalloc.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar.c \
		  ft_putchar_fd.c \
		  ft_putendl.c \
		  ft_putendl_fd.c \
		  ft_putnbr.c \
		  ft_putnbr_fd.c \
		  ft_putstr.c \
		  ft_putstr_fd.c \
		  ft_strcat.c \
		  ft_strchr.c \
		  ft_strchr_len.c \
		  ft_strcmp.c \
		  ft_strcpy.c \
		  ft_strdup.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlen.c \
		  ft_strncat.c \
		  ft_strncmp.c \
		  ft_strncpy.c \
		  ft_strnew.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strstr.c \
		  ft_strsub.c \
		  ft_tolower.c \
		  ft_toupper.c \
		ft_itoa.c \
		ft_countwords.c
CFLAGS = -Wall -Wextra -Werror
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

#%.o: %.c
$(OBJ):
	    gcc $(FLAGS) -I ../includes/ -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

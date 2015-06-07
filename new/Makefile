# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoudert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/13 14:48:43 by scoudert          #+#    #+#              #
#    Updated: 2015/06/07 05:44:12 by mgrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g

MLX = -framework OpenGL -framework AppKit -L mlx/minilibx_macos/ -lmlx

DEBUG = $(CFLAGS) -g

NAME = fdf

CC = gcc

SRC = main.c \
	  get_map.c \
	  fdf_mlx.c \
	  fdf_img.c \
	  fdf_tracer.c \
	  ft_strtofdf.c \
	  fdf_trace_all.c \
	  test_get_map.c \
	  fdf_col.c \
	  fdf_proj.c

HEADER = ./libft/includes/

OBJ = $(SRC:.c=.o)

RM = rm -f

.PHONY: all, clean, fclean, re

all:
	@make $(NAME)

$(NAME): $(SRC)
	@make -C libft/
	@echo "[fdf]\033[32mCompile all \".c\"\033[0m"
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) libft/libft.a
	@echo "[fdf]\033[36mCreate $(NAME) executable \033[0m"

clean:
	@make -C libft/ clean
	@echo "[fdf]\033[31mDelete all \".o\"\033[0m"
	@$(RM) $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@echo "[fdf]\033[31mDelete $(NAME) executable\033[0m"
	@$(RM) $(NAME)

re: fclean all

debug:
	@make -C libft/ fclean
	@make -C libft/ debug
	@echo "\033[32mCompile all \".c\" with debug flag\033[0m"
	@$(CC) $(DEBUG) $(CFLAGS) -c $(SRC
	@$(CC) $(DEBUG) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) libft/libft.a
	@echo "[fdf]\033[36mCreate $(NAME) (debug version)\033[0m"

mlx_free:
	@make -C libft/ fclean
	@make -C libft/ debug
	@echo -e "\033[32mCompile all \".c\" with debug flag\033[0m"
	@$(CC) $(DEBUG) -c $(SRC) -I $(HEADER)
	@$(CC) $(DEBUG) -o $(NAME) $(OBJ) libft/libft.a
	@echo -e "[fdf]\033[36mCreate $(NAME) (debug version)(mlx not linked)\033[0m"

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/11 22:05:57 by mgrimald          #+#    #+#              #
#    Updated: 2015/06/11 22:07:59 by mgrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

DEBUG = $(CFLAGS) -g

NAME = fdf

MLX_DIR = mlx/minilibx_macos/

MLX = -L$(MLX_DIR) -framework OpenGL -framework AppKit -lmlx

CC = gcc

SRC = main.c \
	  get_map.c \
	  ft_strtofdf.c \
	  fdf_mlx.c \
	  fdf_img.c \
	  fdf_tracer.c \
	  fdf_trace_all.c \
	  fdf_proj.c

HEADER = ./libft/includes/

OBJ = $(SRC:.c=.o)

RM = rm -f

.PHONY: all, clean, fclean, re

all:
	@make $(NAME)

$(NAME): $(SRC)
	@make -C libft/
	@make -C $(MLX_DIR)
	@echo "[fdf]\033[32mCompile all \".c\"\033[0m"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(MLX_DIR)/libmlx.a mlx/minilibx_macos/libmlx.a $(MLX) libft/libft.a
	@echo "[fdf]\033[36mCreate $(NAME) executable \033[0m"

clean:
	@make -C libft/ clean

fclean:
	@make -C libft/ fclean
	@make -C $(MLX_DIR) clean
	@echo "[fdf]\033[31mDelete $(NAME) executable\033[0m"
	@$(RM) $(NAME)

re: fclean all

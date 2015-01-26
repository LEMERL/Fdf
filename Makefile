# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoudert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/13 14:48:43 by scoudert          #+#    #+#              #
#    Updated: 2015/01/25 17:54:56 by mgrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

MLX = -L/usr/x11/lib -lmlx -lXext -lX11

DEBUG = $(CFLAGS) -g

NAME = fdf

CC = gcc

SRC = main.c \
	  ft_strtofdf.c \
	  ft_double_tab_del.c \
	  get_map.c \
	  fdf_col.c \
	  fdf_mlx.c \
	  fdf_proj.c \
	  fdf_trace_all.c \
	  fdf_tracer.c


HEADER = libft/includes

OBJ = $(SRC:.c=.o)

RM = rm -f

.PHONY: all, clean, fclean, re

all:
	@make $(NAME)

$(NAME): $(SRC)
	@make -C libft/ fclean
	@make -C libft/
	@make -C minilibx_macos/ clean
	@make -C minilibx_macos/
	@echo "\033[32mCompile all \".c\"\033[0m"
	@$(CC) $(CFLAGS) $(MLX) -c $(SRC) -I $(HEADER)
	@$(CC) $(CFLAGSGS) $(MLX) -o $(NAME) $(OBJ) libft/libft.a
	@echo "\033[36mCreate fdf executable \033[0m"


clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean
	@echo "\033[31mDelete all \".o\"\033[0m"
	@$(RM) $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@echo "\033[31mDelete fdf executable\033[0m"
	@$(RM) $(NAME)

re: fclean all

debug:
	@make -C libft/ fclean
	@make -C libft/ debug
	@make -C minilibx_macos/ clean
	@make -C minilibx_macos/
	@echo "\033[32mCompile all \".c\" with debug flag\033[0m"
	@$(CC) $(DEBUG) $(CFLAGS) -c $(SRC) -I $(HEADER)
	@$(CC) $(DEBUG) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a
	@echo "\033[36mCreate fdf\033[0m"

mlx_free:
	@make -C libft/ fclean
	@make -C libft/ debug
	@echo -e "\033[32mCompile all \".c\" with debug flag\033[0m"
	@$(CC) $(DEBUG) -c $(SRC) -I $(HEADER)
	@$(CC) $(DEBUG) -o $(NAME) $(OBJ) libft/libft.a
	@echo -e "\033[36mCreate fdf\033[0m"
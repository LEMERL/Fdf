# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 16:10:00 by mgrimald          #+#    #+#              #
#    Updated: 2015/06/11 22:10:24 by mgrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC = ft_lstdel.c ft_memdel.c ft_putnbr_fd.c ft_strdel.c ft_strmap.c \
ft_strrchr.c ft_toupper.c ft_atoi.c ft_lstdelone.c ft_memmove.c ft_putstr.c \
ft_strdup.c ft_strmapi.c ft_strrev.c ft_bzero.c ft_lstnew.c ft_memset.c \
ft_putstr_fd.c ft_strequ.c ft_strncat.c ft_strsplit.c ft_isalnum.c \
ft_memalloc.c ft_putchar.c ft_strcat.c ft_striter.c ft_strncmp.c ft_strstr.c\
ft_isalpha.c ft_memccpy.c ft_putchar_fd.c ft_strchr.c ft_striteri.c \
ft_strncpy.c ft_strsub.c ft_isascii.c ft_memchr.c ft_putendl.c ft_strclr.c\
ft_strjoin.c ft_strnequ.c ft_strtrim.c ft_isdigit.c ft_memcmp.c \
ft_putendl_fd.c ft_strcmp.c ft_strlcat.c ft_strnew.c ft_swap.c ft_memcpy.c\
ft_lstaddend.c ft_lstcountbytes.c del.c ft_itoa.c ft_lstiter.c ft_lstmap.c \
ft_lstcountelements.c ft_putnbr.c ft_strlen.c ft_strnstr.c ft_tolower.c \
ft_isprint.c ft_strcpy.c ft_lstadd.c ft_put_error.c ft_isspace.c \
get_next_line.c ft_hexatodeci.c ft_double_tab_del.c ft_count_word.c \
ft_tab_divers.c ft_atoi_i.c

OBJ = $(SRC:.c=.o)

RM = rm -f

.PHONY: all, clean, fclean, re, debug

all:
	@make $(NAME)

$(NAME):
	@echo "[lft]\033[32mCompile all \".c\" using $(CC)\033[0m"
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@echo "[lft]\033[36mCreate $(NAME) \033[0m"
	@ranlib $(NAME)

clean:
	@echo "[lft]\033[31mDelete all \".o\"\033[0m"
	@$(RM) $(OBJ)

fclean: clean
	@echo "[lft]\033[31mDelete $(NAME)\033[0m"
	@$(RM) $(NAME)

re: fclean all

debug:
	@echo "[lft]\033[32mCompile all \".c\" using $(CC) and debug flag\033[0m"
	@$(CC) -g $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@echo "[lft]\033[36mCreate $(NAME) debug\033[0m"
	@ranlib $(NAME)

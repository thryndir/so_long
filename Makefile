# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 20:04:03 by lgalloux          #+#    #+#              #
#    Updated: 2023/12/30 13:27:52 by lgalloux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Game
CC 	= cc
CFLAGS	= -Wextra -Wall -Werror -g
HEADER = -Iinclude
LIB = lib/libft.a
LFLAGS	= -Llib -lmlx42 -ldl -lglfw -pthread

FILES = main so_long_utils parsing create_map\

SRC_DIR = src/
OBJ_DIR = obj/

SRCS	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIB)
	$(CC) $(OBJS) -o $(NAME) $(LFLAGS) $(LIB)

$(LIB):
	# $(MAKE) -C lib/Libft
	mv lib/Libft/libft.a ./lib

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(HEADER) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME) $(LIB)

re: fclean all

.PHONY: all, clean, fclean, re
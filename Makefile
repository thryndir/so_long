# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 20:04:03 by lgalloux          #+#    #+#              #
#    Updated: 2024/01/05 18:09:05 by lgalloux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Game
CC 	= cc
CFLAGS	= -Wextra -Wall -Werror -g
HEADER = -Iinclude
LIB = lib/Libft/libft.a
LFLAGS	= -Llib -lmlx42 -ldl -lglfw -pthread

FILES = main verif struct_init create_map\

SRC_DIR = src/
OBJ_DIR = obj/

SRCS	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIB)
	$(CC) $(OBJS) -o $(NAME) $(LFLAGS) $(LIB) 

$(LIB):
	make -C lib/Libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

$(OBJ_DIR):
	mkdir $@

clean:
	rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	make fclean -C lib/Libft

re: fclean all

.PHONY: all, clean, fclean, re
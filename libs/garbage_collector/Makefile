# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 03:36:39 by asioud            #+#    #+#              #
#    Updated: 2023/07/04 16:59:25 by asioud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

LIB_NAME = libgc.a


SRC_FILES = memory.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(LIB_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_NAME): $(OBJ_FILES)
	ar rcs $@ $(OBJ_FILES)

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(LIB_NAME)
	
.PHONY: all clean

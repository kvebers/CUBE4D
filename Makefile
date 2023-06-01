# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 02:09:51 by asioud            #+#    #+#              #
#    Updated: 2023/06/01 08:42:20 by asioud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
RM			=	rm -rf
NAME		=	cub3D
BONUS 		=	cub4D
USER		=	$(shell whoami)
LIBFT		=	libs/libft/libft.a
LIBMLX		=	libs/MLX42/build/libmlx42.a
CFLAGS		=	-Wall -Wextra -Werror -g -Wno-gnu-include-next -I/LeakSanitizer/include
SRC_DIR		=	src/mandatory/
OBJ_DIR		=	obj/mandatory/
SRC_DIR_B	=	src/bonus/
OBJ_DIR_B	=	obj/bonus/
LIBS 		=	-L/Users/$(USER)/.brew/Cellar/glfw/3.3.8/lib -lglfw
FRAMEWORK	=	-framework Cocoa -framework OpenGL -framework IOKit
HEADER_FILES	=	-I./src/mandatory -I./libs/libft/includes -I./libs/MLX42/include/MLX42

SOURCE		=	main \
				parsing/parser \
				parsing/check_texture \
				parsing/map \
				parsing/player \
				init/utils \
				init/keyhooks \
				init/minimap \
				init/rendermap \
				init/game \
				init/vectors \
				init/move_valid \
				init/debug \
				init/render_texture \
				init/render_background \
				init/rotation \

SOURCE_B	=	main \
				parsing/parser \
				parsing/check_texture \
				parsing/map \
				parsing/player \
				init/utils \
				init/keyhooks \
				init/minimap \
				init/rendermap \
				init/game \
				init/vectors \
				init/move_valid \
				init/debug \
				init/render_texture \
				init/render_background \
				init/rotation \
				
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SOURCE)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SOURCE)))

SRC_B 		= 	$(addprefix $(SRC_DIR_B), $(addsuffix .c, $(SOURCE_B)))
OBJ_B 		= 	$(addprefix $(OBJ_DIR_B), $(addsuffix .o, $(SOURCE_B)))

all: $(NAME)
bonus: $(BONUS)

install_glfw:
	@if [ ! -f $(LIBMLX) ]; then \
		git submodule update --init --recursive --remote; \
		brew uninstall glfw; \
		cmake -S libs/MLX42/ -B libs/MLX42/build -DGLFW_FETCH=1; \
		make -C libs/MLX42/build; \
		brew install glfw; \
		echo "GLFW installed"; \
	fi

$(LIBFT):
	@git submodule update --init --recursive --remote
	@make -C libs/libft
	@echo "Libft installed"

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJ) $(LIBMLX) $(FRAMEWORK) $(LIBS) -o $(NAME)


$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADER_FILES) -c $< -o $@

$(OBJ_DIR_B)%.o : $(SRC_DIR_B)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADER_FILES) -c $< -o $@

$(LIBMLX): install_glfw

$(BONUS): $(LIBFT) $(LIBMLX) $(OBJ_B) 
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJ_B) $(LIBMLX) $(FRAMEWORK) $(LIBS) -o $(BONUS)

clean:
	@$(RM) obj
	@make clean -C ./libs/libft


fclean: clean
	@$(RM) $(NAME) $(BONUS)
	# @make fclean -C ./libs/libft


re:
	@make fclean
	@make


.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 02:09:51 by asioud            #+#    #+#              #
#    Updated: 2023/06/01 16:19:20 by kvebers          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
RM			=	rm -rf
NAME		=	cub3D
NAME_BONUS	=	cub4D
USER		=	$(shell whoami)
LIBFT		=	libs/libft/libft.a
LIBMLX		=	libs/MLX42/build/libmlx42.a
CFLAGS		=	-Wall -Wextra -Werror -g
SRC_DIR		=	src/
SRC_BON		=	bonus/
OBJ_DIR		=	obj/
LIBS 		=	-L/Users/$(USER)/.brew/Cellar/glfw/3.3.8/lib -lglfw
FRAMEWORK	=	-framework Cocoa -framework OpenGL -framework IOKit
VPATH		=	$(SRC_DIR):$(SRC_BON)

SOURCE_BONUS =	main \
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
				init/render_texture \
				init/render_background \
				init/rotation \
				init/intro

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
				init/render_texture \
				init/render_background \
				init/rotation
				
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SOURCE)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SOURCE)))
SRC_B		=	$(addprefix $(SRC_BON), $(addsuffix .c, $(SOURCE_BONUS)))
OBJ_B		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SOURCE_BONUS)))

all: $(NAME)

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


$(OBJ_DIR)%.o : %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADER_FILES) -c $< -o $@

$(LIBMLX): install_glfw \

bonus: $(LIBFT) $(LIBMLX) $(OBJ_B)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJ_B) $(LIBMLX) $(FRAMEWORK) $(LIBS) -o $(NAME_BONUS)

clean:
	@$(RM) obj
	@$(RM) $(OBJ_B)
	@make clean -C ./libs/libft


fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	# @make fclean -C ./libs/libft


re:
	@make fclean
	@make


re_b:
	@make fclean
	@make bonus


.PHONY: all clean fclean re bonus re_b

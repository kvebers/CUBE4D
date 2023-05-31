# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 02:09:51 by asioud            #+#    #+#              #
#    Updated: 2023/05/31 14:20:32 by kvebers          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
RM			=	rm -rf
NAME		=	cub3D
USER		=	$(shell whoami)
LIBFT		=	libs/libft/libft.a
LIBMLX		=	libs/MLX42/build/libmlx42.a
CFLAGS		=	-Wall -Wextra -Werror -g -Wno-gnu-include-next -I/LeakSanitizer/include
SRC_DIR		=	src/
OBJ_DIR		=	obj/
LIBS 		=	-L/Users/$(USER)/.brew/Cellar/glfw/3.3.8/lib -lglfw
FRAMEWORK	=	-framework Cocoa -framework OpenGL -framework IOKit

SOURCE		=	main \
				parsing/parser \
				parsing/check_texture \
				parsing/map \
				parsing/player \
				init/init \
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
				
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SOURCE)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SOURCE)))

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


$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADER_FILES) -c $< -o $@

$(LIBMLX): install_glfw

clean:
	@$(RM) obj
	@make clean -C ./libs/libft


fclean: clean
	@$(RM) $(NAME)
	# @make fclean -C ./libs/libft


re:
	@make fclean
	@make


.PHONY: all clean fclean re

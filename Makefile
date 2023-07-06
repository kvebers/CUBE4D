# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 02:09:51 by asioud            #+#    #+#              #
#    Updated: 2023/07/06 15:15:51 by asioud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
RM			=	rm -rf
NAME		=	cub3D
NAME_BONUS	=	cub4D
USER		=	$(shell whoami)
GC 			=	libs/garbage_collector/libgc.a
LIBFT		=	libs/libft/libft.a
LIBMLX		=	libs/MLX42/build/libmlx42.a
CFLAGS		=	-g
SRC_DIR		=	src/mand
SRC_BON		=	src/bonus/
OBJ_DIR		=	obj/
OBJ_DIR_B		=	obj_b/
LIBS 		=	-L/Users/$(USER)/.brew/Cellar/glfw/3.3.8/lib -lglfw
FRAMEWORK	=	-framework Cocoa -framework OpenGL -framework IOKit
HEADER_FILES=	-I./ -I./libs/libft/includes -I./libs/MLX42/include/MLX42
VPATH		=	$(SRC_DIR):$(SRC_BON)

SOURCE_BONUS =	main_b \
				init/free_textures \
				parsing/map_b \
				parsing/utils_b \
				parsing/player_b \
				parsing/parser_b \
				parsing/init_map_b \
				parsing/set_params_b \
				parsing/check_texture_b \
				parsing/set_directions_b \
				init/utils_b \
				init/keyhooks_b \
				init/minimap_b \
				init/rendermap_b \
				init/game_b \
				init/vectors_b \
				init/move_valid_b \
				init/render_texture_b \
				init/render_background_b \
				init/rotation_b \
				init/mousehook_b \
				init/shaders_b \
				init/doors_b \
				init/sound_b \
				init/gun_b \
				init/scenarios \
				init/enemy_b \
				init/render_end \

SOURCE		=	main \
				parsing/map \
				parsing/utils \
				parsing/player \
				parsing/parser \
				parsing/init_map \
				parsing/set_params \
				parsing/check_texture \
				parsing/set_directions \
				init/game \
				init/utils \
				init/minimap \
				init/vectors \
				init/rotation \
				init/keyhooks \
				init/rendermap \
				init/move_valid \
				init/render_texture \
				init/render_background \

SSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SOURCE)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SOURCE)))
SRC_B		=	$(addprefix $(SRC_BON), $(addsuffix .c, $(SOURCE_BONUS)))
OBJ_B		=	$(addprefix $(OBJ_DIR_B), $(addsuffix .o, $(SOURCE_BONUS)))

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
	@cd libs/garbage_collector && make
	$(CC) $(HEADER_FILES) $(CFLAGS)  $(LIBFT) $(GC) $(OBJ) $(LIBMLX) $(FRAMEWORK) $(LIBS) -o $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(RM) $(OBJ_B)

$(OBJ_DIR)%.o : %.c
	@mkdir -p $(@D)
	@$(CC)  $(HEADER_FILES) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_B)%.o : %.c
	@mkdir -p $(@D)
	@$(CC)  $(HEADER_FILES) $(CFLAGS) -c $< -o $@

$(LIBMLX): install_glfw \

bonus: $(LIBFT) $(LIBMLX) $(OBJ_B)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJ_B) $(LIBMLX) $(FRAMEWORK) $(LIBS) -o $(NAME_BONUS)
	@$(RM) obj
	@$(RM) $(NAME)

clean:
	@$(RM) obj
	@$(RM) obj_b
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
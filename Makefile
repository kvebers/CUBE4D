# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 02:09:51 by asioud            #+#    #+#              #
#    Updated: 2023/05/23 07:07:17 by asioud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
RM			=	rm -rf
NAME		=	cub3D
USER		=	$(shell whoami)
LIBFT		=	libs/libft/libft.a
LIBMLX		=	libs/MLX42/build/libmlx42.a
CFLAGS		=	-Wall -Wextra -Werror
SRC_DIR		=	src/
OBJ_DIR		=	obj/
FRAMEWORK	=	-framework Cocoa -framework OpenGL -framework IOKit

SOURCE		=	main \
				parsing/parser \
				

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SOURCE)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SOURCE)))

all: $(NAME)

install_glfw:
	@if [ -z "$(LIBMLX)" ]; then \
		git submodule update --init --recursive --remote; \
		brew uninstall glfw; \
		cmake -S libs/MLX42/ -B libs/MLX42/build -DGLFW_FETCH=1; \
		make -C libs/MLX42/build; \
		brew install glfw; \
		echo "GLFW installed"; \
	else \
		echo "GLFW already installed"; \
	fi



$(LIBFT):
	@git submodule update --init --recursive --remote
	@make -C libs/libft
	@echo "Libft installed"

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJ) $(LIBMLX) $(FRAMEWORK) -o $(NAME)


$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $@

$(LIBMLX): install_glfw
	@echo "MLX installed"

clean:
	@$(RM) obj
	@make clean -C ./libs/libft


fclean: clean
	@$(RM) $(NAME)
	# @make fclean -C ./libs/libft


re:
	@make fclean
	@make


.PHONY: all clean fclean re run no_glfw have_glfw 

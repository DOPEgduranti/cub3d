# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 10:21:25 by gduranti          #+#    #+#              #
#    Updated: 2024/05/14 16:43:59 by gduranti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = 

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLXFLAGS = -lX11 -lXext -lm

DEPS = includes/

NAME = cub3d

SRC_DIR = src
UTILS_DIR = $(SRC_DIR)/utils
GENERATOR_DIR = $(SRC_DIR)/generator

SRC = $(SRC_DIR)/main.c

UTILS = $(UTILS_DIR)/error.c

GENERATOR = $(GENERATOR_DIR)/datagen.c \
	$(GENERATOR_DIR)/mapgen.c

SRCS = $(SRC) \
	$(UTILS) \
	$(GENERATOR)

OBJ_DIR = obj
OBJ_FOLD = $(OBJ_DIR)/$(SRC_DIR)/$(UTILS_DIR) $(OBJ_DIR)/$(SRC_DIR)/$(GENERATOR_DIR)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

$(OBJ_DIR)/%.o: %.c
	make all -C $(LIBFT_DIR)
	make all -C $(MLX_DIR)
	mkdir -p $(OBJ_FOLD)
	$(CC) $(CFLAGS) -c $< $(MLX) $(MLXFLAGS) $(LIBFT) -I $(DEPS) -o $@

$(NAME): $(OBJ)
	make all -C $(LIBFT_DIR)
	make all -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLXFLAGS) $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re	

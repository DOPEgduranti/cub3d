# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 10:21:25 by gduranti          #+#    #+#              #
#    Updated: 2024/05/14 12:40:41 by gduranti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = 

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLXFLAGS = -lX11 -lXext -lm

DEPS = includes/ libft/

NAME = cub3d

SRC_DIR = src
UTILS_DIR = $(SRC_DIR)/utils

SRC = $(SRC_DIR)/main.c

UTILS = $(UTILS_DIR)/

SRCS = $(SRC)

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

OBJ_FOLD = $(OBJ_DIR)/$(SRC_DIR)/$(UTILS_DIR)

$(OBJ_DIR)/%.o: %.c $(DEPS)
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

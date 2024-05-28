# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 10:21:25 by gduranti          #+#    #+#              #
#    Updated: 2024/05/28 11:27:50 by gduranti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLXFLAGS = -lX11 -lXext -lm

DEPS = includes/

NAME = cub3d

SRC_DIR = src
UTILS_DIR = utils
GENERATOR_DIR = generator
EVENTS_DIR = events
GRAPHICS_DIR = graphic

SRC = main.c

UTIL = conversion.c \
	debug.c \
	dup_funct.c \
	error.c \
	free_funct.c \
	img.c \
	is_funct.c \
	size_funct.c
UTILS = $(addprefix $(UTILS_DIR)/, $(UTIL))

GENERATOR = datagen.c \
	mapgen.c \
	player_init.c \
	texturegen.c \
	texturegen_utils.c
GENERATORS = $(addprefix $(GENERATOR_DIR)/, $(GENERATOR))

EVENT = events.c \
	key_events.c \
	movement.c \
	rotation.c
EVENTS = $(addprefix $(EVENTS_DIR)/, $(EVENT))

GRAPHIC = raycasting.c \
	render.c \
	texture.c
GRAPHICS = $(addprefix $(GRAPHICS_DIR)/, $(GRAPHIC))

SRCS = $(addprefix $(SRC_DIR)/, $(SRC) $(UTILS) $(GENERATORS) $(EVENTS) $(GRAPHICS))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -I$(MLX_DIR) -I$(DEPS) -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make all -C $(LIBFT_DIR)
	make all -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLXFLAGS) $(LIBFT) -I$(MLX_DIR) -I$(DEPS) -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re	

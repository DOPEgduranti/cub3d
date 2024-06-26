# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 10:21:25 by gduranti          #+#    #+#              #
#    Updated: 2024/06/07 11:51:50 by gduranti         ###   ########.fr        #
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

NAME = cub3D

BONUS_NAME = $(NAME)_bonus
BONUS_FLAGS = -D BONUS=1

SRC_DIR = src
UTILS_DIR = utils
GENERATOR_DIR = generator
EVENTS_DIR = events
GRAPHICS_DIR = graphic
BONUS_DIR = bonus

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

GRAPHIC = raycast.c \
	render.c \
	texture.c
GRAPHICS = $(addprefix $(GRAPHICS_DIR)/, $(GRAPHIC))

BONUS = create_bonus.c \
	map_bonus.c \
	minimap_bonus.c \
	movement_bonus.c \
	raycast_bonus.c \
	shoot_bonus.c \
	sprites_bonus.c
BONUSES = $(addprefix $(BONUS_DIR)/, $(BONUS))

SRCS = $(addprefix $(SRC_DIR)/, $(SRC) $(UTILS) $(GENERATORS) $(EVENTS) $(GRAPHICS) $(BONUSES))

OBJ_DIR = obj
BONUS_OBJ_DIR = bonus_obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR)/, $(SRCS:.c=.o))

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -I$(MLX_DIR) -I$(DEPS) -o $@

$(BONUS_OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< $(BONUS_FLAGS) -I$(MLX_DIR) -I$(DEPS) -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make all -C $(LIBFT_DIR)
	make all -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLXFLAGS) $(LIBFT) -I$(MLX_DIR) -I$(DEPS) -o $@

bonus: $(BONUS_OBJ)
	make all -C $(LIBFT_DIR)
	make all -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(MLX) $(MLXFLAGS) $(LIBFT) -I$(MLX_DIR) -I$(DEPS) -o $(BONUS_NAME)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)
	rm -rf $(BONUS_OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

play:
	rm -rf $(BONUS_OBJ_DIR)
	rm -f $(BONUS_NAME)
	make bonus
	./cub3D_bonus map/mapTest.cub

re: fclean all

.PHONY: all bonus clean fclean play re

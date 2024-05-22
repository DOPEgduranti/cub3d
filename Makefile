# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 10:21:25 by gduranti          #+#    #+#              #
#    Updated: 2024/05/22 15:41:03 by gduranti         ###   ########.fr        #
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
UTIL_DIR = utils
GENERATOR_DIR = generator
<<<<<<< HEAD
EVENT_DIR = events
=======
EVENTS_DIR = events
GRAPHICS_DIR = graphic
>>>>>>> 361e6247634075974bcfa3f4dfeb389722b98dc1

SRC = main.c \
	gamestart.c

UTIL = conversion.c \
	debug.c \
	dup_funct.c \
	error.c \
	img.c \
	is_funct.c \
	size_funct.c
UTILS = $(addprefix $(UTILS_DIR)/, $(UTIL))

GENERATOR = datagen.c \
	mapgen.c \
	player_dir.c \
	texturegen.c
GENERATORS = $(addprefix $(GENERATOR_DIR)/, $(GENERATOR))

<<<<<<< HEAD
EVENT = key_events.c \
	mouse_events.c \
	events.c
EVENTS = $(addprefix $(EVENT_DIR)/, $(EVENT))

SRCS = $(addprefix $(SRC_DIR)/, $(SRC) $(UTILS) $(GENERATORS) $(EVENTS))
=======
EVENT = events.c \
	key_events.c \
	mouse_events.c
EVENTS = $(addprefix $(EVENTS_DIR)/, $(EVENT))

GRAPHIC = graph_utils.c \
	raycasting.c \
	render.c \
	texture.c
GRAPHICS = $(addprefix $(GRAPHICS_DIR)/, $(GRAPHIC))

SRCS = $(addprefix $(SRC_DIR)/, $(SRC) $(UTILS) $(GENERATORS) $(EVENTS) $(GRAPHICS))
>>>>>>> 361e6247634075974bcfa3f4dfeb389722b98dc1

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

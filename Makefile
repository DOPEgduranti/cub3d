# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 10:21:25 by gduranti          #+#    #+#              #
#    Updated: 2024/05/16 15:53:34 by sgarigli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3

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
EVENT_DIR = events

SRC = main.c

UTIL = error.c
UTILS = $(addprefix $(UTIL_DIR)/, $(UTIL))

GENERATOR = datagen.c \
	mapgen.c \
	texturegen.c
GENERATORS = $(addprefix $(GENERATOR_DIR)/, $(GENERATOR))

EVENT = key_events.c \
	mouse_events.c \
	events.c
EVENTS = $(addprefix $(EVENT_DIR)/, $(EVENT))

SRCS = $(addprefix $(SRC_DIR)/, $(SRC) $(UTILS) $(GENERATORS) $(EVENTS))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -I $(DEPS) -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make all -C $(LIBFT_DIR)
	make all -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLXFLAGS) $(LIBFT) -I $(DEPS) -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re	

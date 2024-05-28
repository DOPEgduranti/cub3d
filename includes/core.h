/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:35:09 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:23:31 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "../libft/get_next_line_bonus.h"
# include "../libft/ft_printf.h"
# include <mlx.h>
# include <mlx_int.h>
# include <X11/keysym.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# define HEIGHT 720
# define WIDTH 1080
# define TXTR_SIZE 64
# define RSPEED 0.020
# define MSPEED 0.050

typedef enum s_txtr_index
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_txtr_index;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_color
{
	int		value;
	char	*hex;
}	t_color;

typedef struct s_myImg
{
	t_img	*img;
	int		*addr;
	int		bpp;
	int		size_l;
	int		endian;
}	t_myImg;

typedef struct s_textures
{
	int				size;
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	t_color			col_floor;
	t_color			col_ceiling;
	int				**txtrs;
	t_txtr_index	index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_textures;

typedef struct s_map
{
	char		*map_str;
	char		**map_mtx;
	t_vector	size;
}	t_map;

typedef struct s_ray
{
	double		camera_x;
	t_vector	direction;
	t_vector	map;
	t_vector	step;
	t_vector	side_dist;
	t_vector	delta_dist;
	double		wall_dist;
	double		wall_x;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_ray;

typedef struct s_player
{
	t_vector	position;
	t_vector	direction;
	t_vector	plane;
	t_vector	move;
	char		dir;
	int			has_moved;
	int			rotate;
}	t_player;

typedef struct s_data
{
	int			win_h;
	int			win_w;
	int			img_w;
	int			img_h;
	void		*mlx;
	void		*window;
	int			size_l;
	int			bpp;
	int			endian;
	char		*file_str;
	char		**file_mtx;
	int			**pixels;
	t_player	player;
	t_map		map;
	t_textures	textures;
	t_myImg		background;
	t_ray		ray;
}	t_data;

#endif

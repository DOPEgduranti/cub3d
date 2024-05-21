/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:35:09 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/21 11:54:30 by gduranti         ###   ########.fr       */
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

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_color
{
	int		value;
	char	*hex;
}	t_color;

typedef struct s_myImg
{
	t_img	*img;
	char	*addr;
	int		bpp;
	int		size_l;
	int		endian;
}	t_myImg;
typedef struct s_textures
{
	t_img	*north;
	t_img	*south;
	t_img	*east;
	t_img	*west;
	t_color	col_floor;
	t_color	col_ceiling;
}	t_textures;

typedef struct s_map
{
	char		*name;
	char		*map_str;
	char		**map_mtx;
	t_vector	size;
}	t_map;

typedef struct s_player
{
	t_vector	position;
	char		begin_dir;
}	t_player;

typedef struct s_data
{
	int			img_w;
	int			img_h;
	void		*mlx;
	void		*window;
	int			size_l;
	int			bpp;
	int			endian;
	char		*file_str;
	char		**file_mtx;
	t_player	player;
	t_map		map;
	t_textures	textures;
}	t_data;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:35:09 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/16 16:19:28 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "../libft/get_next_line_bonus.h"
# include "../libft/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*col_floor;
	char	*col_ceiling;
}	t_textures;

typedef struct s_map
{
	t_textures	textures;
	char		*name;
	char		*map_str;
	char		**map_mtx;
}	t_map;

typedef struct s_player
{
	t_vector	position;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		map;
}	t_data;

#endif

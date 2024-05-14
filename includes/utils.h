/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:35:09 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/14 13:00:23 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <errno.h>
#include <math.h>
#include <stdio.h>

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
	char	*name;
	char	**map_mtx;
}	t_map;

typedef struct s_player
{
	t_vector	position;
}	t_player;

typedef struct s_data
{
	t_player	*player;
	t_map		*map;
	t_textures	textures;
}	t_data;

#endif
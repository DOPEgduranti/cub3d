/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datagen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:12:14 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/16 16:21:03 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

t_data	datagen(char *mapname)
{
	t_data	data;

	data = (t_data){0};
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1080, 720, "cub3d");
	data.map = mapgen(mapname, data.mlx);
	if (!data.map.map_mtx)
		return ((t_data){0});
	return (data);
}
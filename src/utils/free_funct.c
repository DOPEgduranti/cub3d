/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:59 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	free_textures(t_textures *txtr)
{
	if (txtr->col_ceiling.hex)
		free(txtr->col_ceiling.hex);
	if (txtr->col_floor.hex)
		free(txtr->col_floor.hex);
	if (txtr->north)
		free (txtr->north);
	if (txtr->south)
		free (txtr->south);
	if (txtr->west)
		free (txtr->west);
	if (txtr->east)
		free (txtr->east);
	ft_freemtx((void **)txtr->txtrs);
}

void	free_map(t_map *map)
{
	if (map->map_mtx)
		ft_freemtx((void **)map->map_mtx);
}

void	free_data(t_data *data)
{
	free_map(&data->map);
	free_textures(&data->textures);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (data->pixels)
		ft_freemtx((void **)data->pixels);
}

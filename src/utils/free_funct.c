/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/03 12:50:47 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

static void	free_txtrs(t_textures *txtr)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (txtr->txtrs[i])
			free(txtr->txtrs[i]);
		i++;
	}
	free(txtr->txtrs);
}

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
	if (BONUS && txtr->door)
		free (txtr->door);
	free_txtrs(txtr);
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

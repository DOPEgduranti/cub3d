/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datagen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:12:14 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/16 12:16:45 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

t_data	datagen(char *mapname)
{
	t_data	data;

	data = (t_data){0};
	data.mlx = mlx_init();
	data.map = mapgen(mapname, &data);
	if (!data.map.map_mtx)
		return ((t_data){0});
	return (data);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:00:56 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/17 10:53:04 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

char	**map_parser(char **mtx, t_data *data)
{
	
}

t_map	mapgen(t_data *data)
{
	t_map	map;
	int		i;

	i = 0;
	map.textures = texturegen(data->file_mtx, data);
	if (map.textures.col_ceiling == NULL)
		return ((t_map){0});
	while (data->file_mtx && data->file_mtx[i] && (ft_isemptyline(data->file_mtx[i]) || txtr_row(data->file_mtx[i]) != NOTHING))
		i++;
	map.map_mtx = map_parser(&(data->file_mtx[i]), data);
	if(!map.map_mtx)
		return ((t_map){0});
  return (map);
}

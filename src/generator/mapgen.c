/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:00:56 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/16 12:16:34 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

t_map	mapgen(char *mapname, t_data *data)
{
	t_map	map;
	int		fd;
	char	*buffer;

	map = (t_map){0};
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		return(gerr("Error: map "), gerr(mapname), gerr(" cannot be opened\n"), (t_map){0});
	map.map_str = NULL;
	buffer = get_next_line(fd);
	while (buffer)
	{
		map.map_str = ft_strjoin_2free(map.map_str, buffer);
		buffer = get_next_line(fd);
	}
	map.map_mtx = ft_split(map.map_str, '\n');
	map.textures = texturegen(map.map_mtx, data);
	return (map);
}
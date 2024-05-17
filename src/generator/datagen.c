/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datagen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:12:14 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/17 15:43:38 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

char	**file_read(char *mapname, t_data *data)
{
	int		fd;
	char	*buffer;

	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		return(gerr("Error: map "), gerr(mapname), gerr(" cannot be opened\n"), NULL);
	buffer = get_next_line(fd);
	data->file_str = ft_calloc(1, sizeof(char));
	while (buffer)
	{
		data->file_str = ft_strjoin_2free(data->file_str, buffer);
		buffer = get_next_line(fd);
	}
	return (ft_split(data->file_str, '\n'));
}

t_data	datagen(char *mapname)
{
	t_data	data;

	data = (t_data){0};
	data.mlx = mlx_init();
	data.file_mtx = file_read(mapname, &data);
	data.map = mapgen(&data);
	ft_printmtx(data.map.map_mtx);
	if (!data.map.map_mtx)
		return ((t_data){0});
	return (data);
}
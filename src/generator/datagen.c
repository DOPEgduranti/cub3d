/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datagen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:12:14 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/27 13:03:55 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

char	**file_read(char *mapname, t_data *data)
{
	int		fd;
	char	*buffer;

	if (ft_strcmp(&mapname[ft_strlen(mapname) - 4], ".cub"))
		return (gerr("Error\nonly *.ber files accepted\n"), NULL);
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		return(gerr("Error\nmap "), gerr(mapname), gerr(" cannot be read\n"), NULL);
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
	data.wih_h = HEIGHT;
	data.win_w = WIDTH;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (data);
	data.window = mlx_new_window(data.mlx, data.win_w, data.wih_h, "cub3d");
	if (!data.window)
		return (mlx_destroy_display(data.mlx), data);
	data.file_mtx = file_read(mapname, &data);
	free(data.file_str);
	if (!data.file_mtx)
		return (data);
	data.textures = texturegen(data.file_mtx, &data);
	if (!data.textures.col_ceiling.hex)
		return (ft_freemtx((void **)data.file_mtx), data);
	data.map = mapgen(&data);
	ft_freemtx((void **)data.file_mtx);
	if (!data.map.map_mtx)
		return (free_textures(&data.textures), data);
	ft_printmtx(data.map.map_mtx);
	init_player_direction(&data);
	return (data);
}

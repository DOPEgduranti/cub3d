/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datagen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/21 11:55:46 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

int count_boxes(char **mtx)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (mtx[i])
	{
		j = 0;
		while (mtx[i][j])
		{
			if (mtx[i][j] == 'B')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	basic_var(t_data *data)
{
	data->win_h = HEIGHT;
	data->win_w = WIDTH;
	data->minimap_h = HEIGHT / 4;
	data->minimap_w = WIDTH / 4;
	data->nbr_boxes = 0;
	data->player.run = 1;
	data->player.stamina = 100;
}

static char	**file_read(char *mapname, t_data *data)
{
	int		fd;
	char	*buffer;

	if (ft_strcmp(&mapname[ft_strlen(mapname) - 4], ".cub"))
		return (err_gen("Error\nonly *.ber files accepted\n"), NULL);
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		return (err_gen("Error\nmap "), err_gen(mapname),
			err_gen(" cannot be read\n"), NULL);
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
	basic_var(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (data);
	data.window = mlx_new_window(data.mlx, data.win_w, data.win_h, "cub3D");
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
	player_init(&data);
	return (data);
}

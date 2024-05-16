/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:32:59 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/16 16:57:52 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void draw_map(t_data *data)
{
	int width = 1080;
	int height = 720;
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int rank = 5;
	fprintf(stderr,"%s",data->map.map_str);
	while (i < width)
	{
		x = (i % (rank * 5)) / rank;
		j = 0;
		while (j < height)
		{
			y = (j % (rank * 5)) / rank;
			if (data->map.map_mtx[y][x] == '1')
				mlx_pixel_put(data->mlx, data->win, i, j, 0x00FF0000);
			else
				mlx_pixel_put(data->mlx, data->win, i, j, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	if (argc != 2)
		return (gerr("Error: wrong number of arguments\n"));
	data = datagen(argv[1]);
	draw_map(&data);
	ft_mlx_hook(&data);
	mlx_hook(data.win, 17, 1L << 17, ft_close_window, &data);
	return (0);
}

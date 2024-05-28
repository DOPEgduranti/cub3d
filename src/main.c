/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:32:59 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 10:52:28 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char **argv)
{
	t_data	data;
	if (argc != 2)
		return (err_gen("Error: wrong number of arguments\n"));
	data = datagen(argv[1]);
	if (!data.map.map_mtx)
	{
		mlx_destroy_window(data.mlx, data.window);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (1);
	}
	render_images(&data);
	ft_mlx_hook(&data);
	return (0);
}
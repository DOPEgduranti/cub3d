/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/30 11:00:36 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bonus.h>

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (err_gen("Error: wrong number of arguments\n"));
	if (BONUS)
		ft_ciao();
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

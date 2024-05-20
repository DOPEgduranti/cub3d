/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:32:59 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/20 12:20:01 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void gamestart(t_data *data)
{
	t_myImg	top;
	t_myImg	bottom;
	
	top = new_image(data, WIDTH, HEIGHT / 2);
	put_color(top, 0, 0, 0x00AA0000, data);
	bottom = new_image(data, WIDTH, HEIGHT / 2);
	put_color(bottom, 0, HEIGHT / 2, 0x0000AA00, data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	if (argc != 2)
		return (gerr("Error: wrong number of arguments\n"));
	data = datagen(argv[1]);
	gamestart(&data);
	ft_mlx_hook(&data);
	return (0);
}
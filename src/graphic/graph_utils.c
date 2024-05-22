/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:01:02 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/22 12:18:41 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphic.h>

void	background_set(t_myImg img, int f_color, int c_color)
{
	int i;
	
	i = 0;
	while (i < WIDTH * HEIGHT * 2)
	{
		*(unsigned int*)(img.addr + i) = c_color;
		i+=sizeof(int);
	}
	while (i < WIDTH * HEIGHT * 4)
	{
		*(unsigned int*)(img.addr + i) = f_color;
		i+=sizeof(int);
	}
}

t_myImg	new_image(t_data *data, int width, int height)
{
	t_myImg img;
	
	img.img = mlx_new_image(data->mlx, width, height);
	img.addr = (int *)mlx_get_data_addr(img.img, &data->bpp, &data->size_l, &data->endian);
	return (img);
}
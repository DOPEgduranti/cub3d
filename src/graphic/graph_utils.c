/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:01:02 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/20 12:11:44 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphic.h>

void	put_color(t_myImg img, int x, int y, int color, t_data *data)
{
	int i;
	
	i = 0;
	while (i < WIDTH * HEIGHT * 2)
	{
		*(unsigned int*)(img.addr + i) = color;
		i+=4;
	}
	mlx_put_image_to_window(data->mlx, data->window, img.img, x, y);
}

t_myImg	new_image(t_data *data, int width, int height)
{
	t_myImg img;
	
	img.img = mlx_new_image(data->mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &data->bpp, &data->size_l, &data->endian);
	return (img);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:59 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphic.h>

// void	background_set(t_myImg img, int f_color, int c_color)
// {
// 	int i;
	
// 	i = 0;
// 	while (i < data->win_w * data->win_h * 2)
// 	{
// 		*(unsigned int*)(img.addr + i) = c_color;
// 		i+=sizeof(int);
// 	}
// 	while (i < data->win_w * data->win_h * 4)
// 	{
// 		*(unsigned int*)(img.addr + i) = f_color;
// 		i+=sizeof(int);
// 	}
// }

t_myImg	new_image(t_data *data, int width, int height)
{
	t_myImg img;
	
	img.img = mlx_new_image(data->mlx, width, height);
	img.addr = (int *)mlx_get_data_addr(img.img, &data->bpp, &data->size_l, &data->endian);
	return (img);
}

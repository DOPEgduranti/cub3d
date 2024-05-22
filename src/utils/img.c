/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:19:43 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/22 12:17:52 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

t_img	*imggen(t_data *data, char *filename)
{
	t_img	*img;

	if (!data || !filename)
		return (NULL);
	img = mlx_xpm_file_to_image(data->mlx, filename, &(data->img_w), &(data->img_h));
	return (img);
}

t_myImg	myImggen(char *filename, t_data *data)
{
	t_myImg	img;

	img = (t_myImg){0};
	img.img = imggen(data, filename);
	if (!img.img)
		return ((t_myImg){0});
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_l, &img.endian);
	if (!img.addr)
		return (mlx_destroy_image(data->mlx, img.img), (t_myImg){0});
	return (img);
}

t_myImg	empty_myImg(t_data *data, int width, int height)
{
	t_myImg	image;

	image = (t_myImg){0};
	image.img = mlx_new_image(data->mlx, width, height);
	if (image.img == NULL)
		return ((t_myImg){0});
	image.addr = (int *)mlx_get_data_addr(image.img, &image.bpp, &image.size_l, &image.endian);
	return (image);
}

void	set_pixel(t_myImg *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_l / 4) + x;
	image->addr[pixel] = color;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:30:04 by mcombeau          #+#    #+#             */
/*   Updated: 2024/05/24 11:25:30 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphic.h>

static void	frame_set(t_data *data, t_myImg *image, int x, int y)
{
	if (data->pixels[y][x] > 0)
		set_pixel(image, x, y, data->pixels[y][x]);
	else if (y < data->wih_h / 2)
		set_pixel(image, x, y, data->textures.col_ceiling.value);
	else if (y < data->wih_h -1)
		set_pixel(image, x, y, data->textures.col_floor.value);
}

static void	render_frame(t_data *data)
{
	t_myImg	image;
	int		x;
	int		y;

	image.img = NULL;
	image = empty_myImg(data, data->win_w, data->wih_h);
	y = 0;
	while (y < data->wih_h)
	{
		x = 0;
		while (x < data->win_w)
		{
			frame_set(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, image.img, 0, 0);
	mlx_destroy_image(data->mlx, image.img);
}

void	render_images(t_data *data)
{
	pixels_init(data);
	raycasting(data);
	render_frame(data);
	// if (BONUS)
	// 	render_minimap(data);
}

// int	render(t_data *data)
// {
// 	data->player.has_moved += move_player(data);
// 	if (data->player.has_moved == 0)
// 		return (0);
// 	render_images(data);
// 	return (0);
// }

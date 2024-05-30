/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/30 11:01:34 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphic.h>
#include <events.h>

static void	frame_set(t_data *data, t_myImg *image, int x, int y)
{
	if (data->pixels[y][x] > 0)
		set_pixel(image, x, y, data->pixels[y][x]);
	else if (y < data->win_h / 2)
		set_pixel(image, x, y, data->textures.col_ceiling.value);
	else if (y < data->win_h -1)
		set_pixel(image, x, y, data->textures.col_floor.value);
}

static void	render_frame(t_data *data)
{
	t_myImg	image;
	int		x;
	int		y;

	image.img = NULL;
	image = myimg_empty(data, data->win_w, data->win_h);
	y = 0;
	while (y < data->win_h)
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

static void	pixels_init(t_data *data)
{
	int	i;

	if (data->pixels)
		ft_freemtx((void **)data->pixels);
	data->pixels = ft_calloc(data->win_h + 1, sizeof(int *));
	if (!data->pixels)
		return (err_malloc(), free_data(data), exit(1));
	i = 0;
	while (i < data->win_h)
	{
		data->pixels[i] = ft_calloc(data->win_w + 1, sizeof(int));
		if (!data->pixels[i])
			return (err_malloc(), free_data(data), exit(1));
		i++;
	}
}

void	render_images(t_data *data)
{
	pixels_init(data);
	raycaster(data);
	render_frame(data);
}

int	render(t_data *data)
{
	data->player.has_moved += ft_movement(data);
	if (data->player.has_moved == 0)
		return (0);
	render_images(data);
	return (0);
}

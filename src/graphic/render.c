/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/04 10:47:27 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphic.h>
#include <events.h>
#include <bonus.h>

static void	frame_set(t_data *data, t_myImg *image, int x, int y)
{
	int			r;
	t_cursor	cent;

	r = fmin(data->minimap_w, data->minimap_h) / 2;
	cent = (t_cursor){data->minimap_w / 2, data->minimap_h / 2};
	if (!((x - cent.x) * (x - cent.x) + (y - cent.y) * (y - cent.y) > r * r)
		&& BONUS && y < data->minimap_h && x < data->minimap_w
		&& ((x + y) % 2 == 1))
		return ;
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
	if (BONUS)
	{
		render_minimap(&image, data);
		render_sprite(&image, data);
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
	raycast(data);
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

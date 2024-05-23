/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:32:59 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/22 16:54:07 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void printalldata(t_data *data)
{
	printf("win_height: %d\n", data->win_height);
	printf("win_width: %d\n", data->win_width);
	printf("img_w: %d\n", data->img_w);
	printf("img_h: %d\n", data->img_h);
	printf("mlx: %p\n", data->mlx);
	printf("window: %p\n", data->window);
	printf("size_l: %d\n", data->size_l);
	printf("bpp: %d\n", data->bpp);
	printf("endian: %d\n", data->endian);
	printf("file_str: %s\n", data->file_str);
	printf("file_mtx: %p\n", data->file_mtx);
	printf("pixels: %p\n", data->pixels);
	printf("player.position.x: %f\n", data->player.position.x);
	printf("player.position.y: %f\n", data->player.position.y);
	printf("player.direction.x: %f\n", data->player.direction.x);
	printf("player.direction.y: %f\n", data->player.direction.y);
	printf("player.plane.x: %f\n", data->player.plane.x);
	printf("player.plane.y: %f\n", data->player.plane.y);
	printf("player.move.x: %f\n", data->player.move.x);
	printf("player.move.y: %f\n", data->player.move.y);
	printf("player.dir: %c\n", data->player.dir);
	printf("player.has_moved: %d\n", data->player.has_moved);
	printf("player.rotate: %d\n", data->player.rotate);
	printf("map.name: %s\n", data->map.name);
	printf("map.map_str: %s\n", data->map.map_str);
	printf("map.map_mtx: %p\n", data->map.map_mtx);
	printf("map.size.x: %f\n", data->map.size.x);
	printf("map.size.y: %f\n", data->map.size.y);
	printf("textures.size: %d\n", data->textures.size);
	printf("textures->north: %s\n", data->textures.north);
	printf("textures->south: %s\n", data->textures.south);
	printf("textures->west: %s\n", data->textures.west);
	printf("textures->east: %s\n", data->textures.east);
	printf("textures.col_floor.value: %d\n", data->textures.col_floor.value);
	printf("textures.col_floor.hex: %s\n", data->textures.col_floor.hex);
	printf("textures.col_ceiling.value: %d\n", data->textures.col_ceiling.value);
	printf("textures.col_ceiling.hex: %s\n", data->textures.col_ceiling.hex);
	printf("textures.txtrs: %p\n", data->textures.txtrs);
	printf("textures.index: %d\n", data->textures.index);
	printf("textures.step: %f\n", data->textures.step);
	printf("textures.pos: %f\n", data->textures.pos);
	printf("textures.x: %d\n", data->textures.x);
	printf("textures.y: %d\n", data->textures.y);
	printf("background.img: %p\n", data->background.img);
	printf("background.addr: %p\n", data->background.addr);
	printf("background.bpp: %d\n", data->background.bpp);
	printf("background.size_l: %d\n", data->background.size_l);
	printf("background.endian: %d\n", data->background.endian);
	printf("ray.camera_x: %f\n", data->ray.camera_x);
	printf("ray.direction.x: %f\n", data->ray.direction.x);
	printf("ray.direction.y: %f\n", data->ray.direction.y);
	printf("ray.map.x: %f\n", data->ray.map.x);
	printf("ray.map.y: %f\n", data->ray.map.y);
	printf("ray.step.x: %f\n", data->ray.step.x);
	printf("ray.step.y: %f\n", data->ray.step.y);
	printf("ray.side_dist.x: %f\n", data->ray.side_dist.x);
	printf("ray.side_dist.y: %f\n", data->ray.side_dist.y);
	printf("ray.delta_dist.x: %f\n", data->ray.delta_dist.x);
	printf("ray.delta_dist.y: %f\n", data->ray.delta_dist.y);
	printf("ray.wall_dist: %f\n", data->ray.wall_dist);
	printf("ray.wall_x: %f\n", data->ray.wall_x);
	printf("ray.side: %d\n", data->ray.side);
	printf("ray.line_height: %d\n", data->ray.line_height);
	printf("ray.draw_start: %d\n", data->ray.draw_start);
	printf("ray.draw_end: %d\n", data->ray.draw_end);
}

int	main(int argc, char **argv)
{
	t_data	data;
	if (argc != 2)
		return (gerr("Error: wrong number of arguments\n"));
	data = datagen(argv[1]);
	printalldata(&data);
	gamestart(&data);
	ft_mlx_hook(&data);
	return (0);
}
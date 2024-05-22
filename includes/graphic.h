/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:01:28 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/22 12:21:08 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include <utils.h>

// graph_utils.c
void	background_set(t_myImg img, int f_color, int c_color);
t_myImg	new_image(t_data *data, int width, int height);

// raycasting.c
int	raycasting(t_player *player, t_data *data);

// texture.c
void	init_pixels(t_data *data);
void	update_pixels(t_data *data, t_textures *tex, t_ray *ray, int x);

// render.c
void	render_images(t_data *data);

#endif
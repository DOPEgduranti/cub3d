/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 12:18:06 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include <utils.h>

// graph_utils.c
void	background_set(t_myImg img, int f_color, int c_color);
t_myImg	new_image(t_data *data, int width, int height);

// raycasting.c
int	raycasting(t_data *data);

// texture.c
void	pixels_init(t_data *data);
void	pixels_update(t_data *data, int x);

// render.c
void	render_images(t_data *data);
int		render(t_data *data);


#endif

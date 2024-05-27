/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:01:28 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/27 15:35:56 by gduranti         ###   ########.fr       */
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
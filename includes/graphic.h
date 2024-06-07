/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/07 09:34:07 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include <utils.h>

// raycast.c
int		raycast(t_data *data);

// texture.c
void	pixels_update(t_data *data, int x);

// render.c

void	render_images(t_data *data);
int		render(t_data *data);

#endif

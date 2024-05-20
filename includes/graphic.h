/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:01:28 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/20 12:16:24 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include <utils.h>

//graph_utils.c
void	put_color(t_myImg img, int x, int y, int color, t_data *data);
t_myImg	new_image(t_data *data, int width, int height);

#endif
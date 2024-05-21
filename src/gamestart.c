/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:22:25 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/21 11:42:04 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void gamestart(t_data *data)
{
	t_myImg	top;
	t_myImg	bottom;
	
	top = new_image(data, WIDTH, HEIGHT / 2);
	put_color(top, 0, 0, 0xAA0000, data);
	bottom = new_image(data, WIDTH, HEIGHT / 2);
	put_color(bottom, 0, HEIGHT / 2, 0x00AA00, data);
}
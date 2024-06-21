/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:25:23 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/21 12:31:32 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphic.h>

void	render_stamina_bar(t_myImg *image, t_data *data)
{
	int		x;
	int		y;
	int		i;
	int		j;

	y = data->win_h - 20;
	i = 0;
	while (i < 20)
	{
		x = data->win_w - 100;
		j = 0;
		while (j < 100)
		{
			if (j < data->player.stamina)
				set_pixel(image, x, y, 0xFFFF00);
			else
				set_pixel(image, x, y, 0x000000);
			x++;
			j++;
		}
		y++;
		i++;
	}
}
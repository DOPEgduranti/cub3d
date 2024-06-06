/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/06 11:15:39 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>
#include <bonus.h>

int	ft_close_window(t_data *data)
{
	free_data(data);
	exit(0);
}

int	ft_key_release(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_s)
		data->player.move.y = 0;
	if (keysym == XK_a || keysym == XK_d)
		data->player.move.x = 0;
	if (keysym == XK_Left || keysym == XK_Right)
		data->player.rotate = 0;
	return (0);
}

int	ft_key_press(int keysym, t_data *data)
{
	if (keysym == 65307)
		ft_close_window(data);
	if (keysym == XK_w)
		data->player.move.y = 1;
	if (keysym == XK_s)
		data->player.move.y = -1;
	if (keysym == XK_a)
		data->player.move.x = -1;
	if (keysym == XK_d)
		data->player.move.x = 1;
	if (keysym == XK_Left)
		data->player.rotate = -1;
	if (keysym == XK_Right)
		data->player.rotate = 1;
	if (keysym == XK_space)
		ft_door(data);
	if (keysym == XK_Shift_L)
		ft_shoot(data);
	return (0);
}

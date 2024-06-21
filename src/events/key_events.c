/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/21 12:20:35 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>
#include <bonus.h>
#include <graphic.h>

void	ft_removeexplosion(t_data *data)
{
	int	i;
	int	j;

	data->player.is_shooting = false;
	i = 0;
	while (i < data->map.size.y)
	{
		j = 0;
		while (j < data->map.size.x)
		{
			if (data->map.map_mtx[i][j] == 'X')
			{
				data->map.map_mtx[i][j] = '0';
				data->nbr_boxes--;
			}
			j++;
		}
		i++;
	}
	ft_shoot(data);
}

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
	if ((keysym == XK_space && BONUS) || data->player.stamina < 10)
		data->player.is_shooting = false;
	if (keysym == XK_Shift_L && BONUS)
		data->player.box = false;
	if ((keysym == XK_Control_L && BONUS) || data->player.stamina < 0)
		data->player.run = 1;
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
	if (keysym == XK_f)
		ft_door(data);
	if (keysym == XK_space && BONUS && data->player.stamina > 10)
		ft_shoot(data);
	if (keysym == XK_Shift_L && BONUS)
		data->player.box = true;
	if (keysym == XK_Control_L && BONUS && data->player.stamina > 0)
		ft_run(data);
	return (0);
}

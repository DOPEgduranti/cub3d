/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:25:47 by sgarigli          #+#    #+#             */
/*   Updated: 2024/05/20 10:32:29 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

int	ft_close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
}

int	ft_keyHook(int keysym, t_data *data)
{
	if (keysym == 65307)
		ft_close_window(data);
	printf("Key %d\n", keysym);
	return (0);
}
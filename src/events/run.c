/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:23:36 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/21 12:25:36 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

void reduce_stamina(t_data *data)
{
	if (data->player.stamina > 0)
		data->player.stamina -= 1.0;
}
void regain_stamina(t_data *data)
{
	if (data->player.stamina < 100)
		data->player.stamina += 0.2;
}

void	ft_run(t_data *data)
{
	data->player.run = 2;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mana.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:17:36 by gduranti          #+#    #+#             */
/*   Updated: 2024/06/21 15:52:21 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

void reduce_mana(t_data *data)
{
	if (data->player.mana > 0)
		data->player.mana -= 1;
}

void regain_mana(t_data *data)
{
	if (data->player.mana <= 100)
		data->player.mana += 0.2;
}

void cast_spell(double *mana)
{
	if (*mana >= 10)
		*mana -= 30;
	if (*mana < 0)
		*mana = 0;
}
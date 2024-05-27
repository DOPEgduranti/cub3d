/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:31:19 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/27 11:33:36 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	free_textures(t_textures *txtr)
{
	int	i;

	if (txtr->col_ceiling.hex)
		free(txtr->col_ceiling.hex);
	if (txtr->col_floor.hex)
		free(txtr->col_floor.hex);
	if (txtr->north)
		free (txtr->north);
	if (txtr->south)
		free (txtr->south);
	if (txtr->west)
		free (txtr->west);
	if (txtr->east)
		free (txtr->east);
	i = 0;
	while (i < 4)
	{
		if (txtr->txtrs[i])
			free(txtr->txtrs[i]);
		i++;
	}
	free(txtr->txtrs);
}

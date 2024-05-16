/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:19:43 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/16 12:23:23 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	*imggen(t_data *data, char *filename)
{
	if (!data || !filename)
		return (NULL);
	return (mlx_xpm_file_to_image(data->mlx, filename, &(data->img_w), &(data->img_h)));
}

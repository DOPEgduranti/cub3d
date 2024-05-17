/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:19:43 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/17 11:39:07 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

t_img	*imggen(t_data *data, char *filename)
{
	t_img	*img;

	if (!data || !filename)
		return (NULL);
	img = mlx_xpm_file_to_image(data->mlx, filename, &(data->img_w), &(data->img_h));
	return (img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:19:43 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/16 16:17:01 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

t_img	*imggen(t_data *data, char *filename)
{
	t_img	*img;

	if (!data || !filename)
		return (NULL);
	printf("%s\n", filename);
	img = mlx_xpm_file_to_image(data->mlx, filename, &(data->img_w), &(data->img_h));
	return (img);
}

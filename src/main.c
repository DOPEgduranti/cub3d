/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:32:59 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/22 16:04:50 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char **argv)
{
	t_data	data;
	if (argc != 2)
		return (gerr("Error: wrong number of arguments\n"));
	data = datagen(argv[1]);
	gamestart(&data);
	ft_mlx_hook(&data);
	return (0);
}
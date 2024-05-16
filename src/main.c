/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:32:59 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/16 11:16:55 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

int	main(int argc, char **argv)
{
	t_data	data;
	if (argc != 2)
		return (gerr("Error: wrong number of arguments\n"));
	data = datagen(argv[1]);
	return (0);
}
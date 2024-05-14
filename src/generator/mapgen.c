/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:00:56 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/14 16:36:22 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <generator.h>

char	**mapgen(char *mapname)
{
	int		fd;
	char	*buffer;
	char	*file_line;
	char	**mapmtx;

	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		return(gerr("Error: map "), gerr(mapname), gerr(" cannot be opened\n"), NULL);
	file_line = NULL;
	buffer = get_next_line(fd);
	while (!buffer)
	{
		file_line = ft_strjoin_2free(file_line, buffer);
		buffer = get_next_line(fd);
	}
	mapmtx = ft_split(file_line, '\n');
	return (free(file_line), mapmtx);
}
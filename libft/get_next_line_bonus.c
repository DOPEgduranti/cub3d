/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/30 11:01:34 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(char *old_str, int fd)
{
	char	*buf;
	int		rd;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	rd = 1;
	while (rd > 0 && ft_strchr(old_str, '\n') == 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(old_str);
			free(buf);
			return (0);
		}
		buf[rd] = '\0';
		old_str = ft_newstrjoin(old_str, buf);
	}
	free(buf);
	return (old_str);
}

char	*get_next_line(int fd)
{
	static char	*old_str[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	old_str[fd] = ft_read(old_str[fd], fd);
	if (!old_str[fd])
		return (NULL);
	line = ft_correctline(old_str[fd]);
	old_str[fd] = ft_resto(old_str[fd]);
	return (line);
}

/*
int	main(void)
{
	int		fd;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}

		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}*/

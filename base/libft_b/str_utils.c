/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/30 09:27:12 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_2free(char *old_str, char *buf)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!old_str)
	{
		old_str = (char *)malloc(1 * sizeof(char));
		if (!old_str || !buf)
			return (NULL);
		old_str[0] = '\0';
	}
	res = malloc(sizeof(char) * (ft_strlen(old_str) + ft_strlen(buf) + 1));
	if (!res)
		return (0);
	i = -1;
	j = 0;
	if (old_str)
		while (old_str[++i] != '\0')
			res[i] = old_str[i];
	while (buf[j] != '\0')
		res[i++] = buf[j++];
	res[ft_strlen(old_str) + ft_strlen(buf)] = '\0';
	free(old_str);
	free(buf);
	return (res);
}

char	*ft_strjoin_2(char *old_str, char *buf)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!old_str)
	{
		old_str = (char *)malloc(1 * sizeof(char));
		if (!old_str || !buf)
			return (NULL);
		old_str[0] = '\0';
	}
	res = malloc(sizeof(char) * (ft_strlen(old_str) + ft_strlen(buf) + 1));
	if (!res)
		return (0);
	i = -1;
	j = 0;
	if (old_str)
		while (old_str[++i] != '\0')
			res[i] = old_str[i];
	while (buf[j] != '\0')
		res[i++] = buf[j++];
	res[ft_strlen(old_str) + ft_strlen(buf)] = '\0';
	free(buf);
	return (res);
}

char	*ft_strndup(char *str, int i)
{
	char	*dst;
	int		j;

	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dst[j] = str[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

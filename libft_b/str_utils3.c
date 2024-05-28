/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 12:18:07 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_char(char *str, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str)
	{
		tmp = malloc(sizeof(char) * 2);
		if (!tmp)
			return (NULL);
		tmp[0] = c;
		tmp[1] = '\0';
		return (tmp);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(str);
	return (tmp);
}

char	*cut_string(int len, char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!ft_strlen(str) || len >= (int)ft_strlen(str))
		return (free(str), NULL);
	tmp = malloc(sizeof(char) * (ft_strlen(str) - len + 1));
	if (!tmp)
		return (NULL);
	while (str[len])
	{
		tmp[i] = str[len];
		i++;
		len++;
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}

char	*strjoin_n_free1(char *line, char *buff, int index)
{
	int		i;
	int		new_str_len;
	char	*new_str;

	i = 0;
	new_str_len = ft_strlen(line) + index;
	new_str = malloc(ft_strlen(line) + index + 1);
	if (new_str)
	{
		while (line[i])
		{
			new_str[i] = line[i];
			i++;
		}
		while (i < new_str_len)
		{
			new_str[i] = buff[i - ft_strlen(line)];
			i++;
		}
		new_str[new_str_len] = '\0';
	}
	free(line);
	return (new_str);
}

char	*ft_strncpy(char *str, int start, int end)
{
	char	*dst;
	int		i;

	if (!str)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (start < end)
	{
		dst[i] = str[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}

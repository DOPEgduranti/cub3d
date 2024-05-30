/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_funct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/30 11:00:36 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

bool	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (true);
	return (false);
}

bool	ft_isemptyline(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (false);
	return (true);
}

bool	ft_isinset(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (true);
		i++;
	}
	return (false);
}

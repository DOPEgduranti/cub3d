/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:07:23 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:21:39 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	ft_hextoi(char *hex, int length)
{
    char	c;
	int		nbr;

	if (length == 0)
        return 0;
    c = hex[length - 1];
	if (ft_isdigit(c))
        nbr =  c - '0';
	else
        nbr =  ft_toupper(c) - 'A' + 10;
    return (nbr + 16 * ft_hextoi(hex, length - 1));
}

void ft_itohex(int dec, char *hex, int *index)
{
    char hexDigits[] = "0123456789ABCDEF";
	int		pos;

    if (dec == 0)
	{
        if (*index == '0')
		{
            hex[(*index)++] = '0';
        }
        return;
    }
    ft_itohex(dec / 16, hex, index);
    pos = dec % 16;
    hex[(*index)++] = hexDigits[pos];
}

int	*find_rgb(char	*str)
{
	int	*rgb;
	int	i;
	int	j;

	i = 0;
	j = 0;
	rgb = ft_calloc(3, sizeof(int));
	if (!rgb)
		return (err_malloc(), NULL);
	while (str && str[i] && ft_isdigit(str[i]) && j < 3)
	{
		rgb[j] = ft_atoi(&str[i]);
		if (rgb[j] > 255 || (rgb[j] == 0 && (str[i] != '0' || ft_isdigit(str[i + 1]))))
			return (free(rgb), NULL);
		while(ft_isdigit(str[i]))
			i++;
		if (str[i] == ',' && j < 2)
			i++;
		j++;
	}
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] || j != 3)
		return (free(rgb), NULL);
	return (rgb);
}

char	*rgb_to_hex(char *str, char *hex)
{
	int		index;
	int		*rgb;

	rgb = find_rgb(str);
	if (!rgb)
		return (free(hex), NULL);
	index = 0;
	ft_itohex(rgb[0], &hex[2], &index);
	index = 0;
	ft_itohex(rgb[1], &hex[4], &index);
	index = 0;
	ft_itohex(rgb[2], &hex[6], &index);
	return (free(rgb), hex);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 12:18:07 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

char	**ft_mtxdup(char **mtx)
{
	char	**dst;
	int		i;

	i = 0;
	dst = ft_calloc(ft_mtxlen(mtx) + 1, sizeof(char *));
	if (!dst)
		return (err_malloc(), NULL);
	while (mtx && mtx[i])
	{
		dst[i] = ft_strdup(mtx[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

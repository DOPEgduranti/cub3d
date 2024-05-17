/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:10:30 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/17 12:22:39 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

char	**ft_mtxdup(char **mtx)
{
	char	**dst;
	int i;

	i = 0;
	dst = ft_calloc(ft_mtxlen(mtx) + 1, sizeof(char *));
	if (!dst)
		return (NULL);
	while (mtx && mtx[i])
	{
		dst[i] = ft_strdup(mtx[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
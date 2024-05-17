/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:10:30 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/17 10:17:52 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

char	**ft_mtxdup(char **mtx)
{
	char	**dst;
	int i;

	i = -1;
	dst = ft_calloc(ft_mtxlen(mtx), sizeof(char *));
	if (!dst)
		return (NULL);
	while (mtx && mtx[++i])
		dst[i] = ft_strdup(mtx[i]);
	dst[i] = NULL;
	return (dst);
}
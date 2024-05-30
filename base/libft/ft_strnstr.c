/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 12:18:07 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	i = 0;
	len_little = ft_strlen(little);
	if (little == NULL || *little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i + len_little <= len)
	{
		if (ft_strncmp(&big[i], little, len_little) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>

int main() 
{
    const char *big = "This is a test string for testing strnstr";
    const char *little = "for";
    size_t len = 100; // Maximum search length

    char *result = strnstr(big, little, len);

    if (result != 0) 
	{
        printf("Substring found: %s\n", result);
    } else 
	{
    	    printf("Substring not found.\n");
	}

	return (0);
}*/
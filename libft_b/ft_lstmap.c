/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by gduranti          #+#    #+#             */
/*   Updated: 2024/05/28 11:53:58 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp_lst;
	t_list	*my_lst;

	if (!lst || !del || !f)
		return (NULL);
	my_lst = NULL;
	while (lst)
	{
		tmp_lst = ft_lstnew(f(lst->content));
		if (!tmp_lst)
		{
			ft_lstclear(&my_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&my_lst, tmp_lst);
		lst = lst->next;
	}
	return (my_lst);
}

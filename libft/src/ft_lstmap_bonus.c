/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:53:31 by secros            #+#    #+#             */
/*   Updated: 2024/11/14 16:26:25 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del) (void *))
{
	t_list	*n_node;
	t_list	*n_lst;
	void	*pt;

	n_lst = NULL;
	while (lst)
	{
		pt = f(lst->content);
		if (!pt)
		{
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		n_node = ft_lstnew(pt);
		if (!n_node)
		{
			if (del)
				del(pt);
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&n_lst, n_node);
		lst = lst->next;
	}
	return (n_lst);
}

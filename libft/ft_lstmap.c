/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:59:37 by wyu               #+#    #+#             */
/*   Updated: 2022/01/03 15:58:19 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_lst;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	node = lst;
	new_head = NULL;
	while (node)
	{
		new_lst = ft_lstnew(f(node->content));
		if (!new_lst)
		{
			if (!del)
			{
				ft_lstclear(&new_head, del);
				return (NULL);
			}
			else
				return (new_head);
		}
		ft_lstadd_back(&new_head, new_lst);
		node = node->next;
	}
	return (new_head);
}

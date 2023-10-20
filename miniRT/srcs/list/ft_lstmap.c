/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:47:16 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/20 15:41:44 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_object	*ft_lstmap(t_object *lst, void *(*f)(void *), void (*del)(void *))
{
	t_object	*head;
	t_object	*new;
	void	*tmp;

	if (!lst || !f | !del)
		return (0);
	head = 0;
	while (lst)
	{
		tmp = f(lst->obj);
		new = object(tmp, 1);
		if (!new)
		{
			del(tmp);
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}

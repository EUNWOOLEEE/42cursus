/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:53:01 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 08:36:31 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

t_list	*ft_lstnew()
{
	t_list	*tmp;

	tmp = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!tmp)
		return (NULL);
	return (tmp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->pre = last;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*cur;
	t_list	*tmp;

	if (!lst)
		return ;
	cur = *lst;
	while (cur)
	{
		tmp = cur->next;
		ft_lstdelone(cur);
		cur = tmp;
	}
	*lst = NULL;
}

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	if (lst->token)
		free(lst->token);
	if (lst->env_key)
		free(lst->env_key);
	if (lst->env_value)
		free(lst->env_value);
	free(lst);
}

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:04:21 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/28 17:10:35 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	ft_lstadd_back(t_object **lst, t_object *new)
{
	t_object	*last;

	if (!lst || !new)
		print_error_exit(MEMORY);
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	new->num = ft_lstsize(*lst);
	last->next = new;
}

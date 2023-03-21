/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:01:47 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/21 15:36:44 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*delete_nod(t_gnl_list **head, t_gnl_list *nod)
{
	t_gnl_list	*tmp;

	tmp = *head;
	if (tmp == nod)
	{
		if (!(tmp->next))
			*head = 0;
		else
			*head = tmp->next;
		free(nod->buff);
		free(nod);
		return (0);
	}
	while (tmp->next != nod)
		tmp = tmp->next;
	tmp->next = nod->next;
	free(nod->buff);
	free(nod);
	return (0);
}

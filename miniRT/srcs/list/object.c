/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:43:59 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/20 16:31:31 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_object	*object(void *content, int type)
{
	t_object	*tmp;

	tmp = (t_object *)ft_calloc(1, sizeof(t_object));
	if (!tmp)
		return (NULL);
	tmp->type = type;
	tmp->obj = content;
	tmp->next = NULL;
	return (tmp);
}

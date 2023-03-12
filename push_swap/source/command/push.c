/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:09 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/12 18:30:11 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	set_idx(int idx, int size)
{
	idx--;
	if (idx == -1)
		idx = size - 1;
	return (idx);
}

char	*pa(t_stack *a, t_stack *b, int print)
{
	if (!(b->in - b->out))
		return (0);
	a->front = set_idx(a->front, a->size);
	a->arr[a->front] = b->arr[b->front];
	b->arr[b->front] = 0;
	b->front = (b->front + 1) % a->size;
	b->out++;
	a->in++;
	if (print)
	{
		write(1, "pa\n", 3);
		return (0);
	}
	return (ft_strdup("pa"));
}

char	*pb(t_stack *a, t_stack *b, int print)
{
	if (!(a->in - a->out))
		return (0);
	b->front = set_idx(b->front, b->size);
	b->arr[b->front] = a->arr[a->front];
	a->arr[a->front] = 0;
	a->front = (a->front + 1) % a->size;
	a->out++;
	b->in++;
	if (print)
	{
		write(1, "pb\n", 3);
		return (0);
	}
	return (ft_strdup("pb"));
}

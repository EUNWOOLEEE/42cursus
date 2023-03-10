/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:09 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/10 21:45:09 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*pa(t_stack *a, t_stack *b, int size, int print)
{
	if (!(b->in - b->out))
		return (0);
	if (!a->front)
		a->front += size - 1;
	else
		a->front = a->front - 1;
	a->arr[a->front] = b->arr[b->front];
	b->arr[b->front] = 0;
	b->front = (b->front + 1) % size;
	b->out++;
	a->in++;
	if (print)
		write(1, "pa\n", 3);
	return (ft_strdup("pa"));
}

char	*pb(t_stack *a, t_stack *b, int size, int print)
{
	if (!(a->in - a->out))
		return (0);
	if (!b->front)
		b->front = size - 1;
	else
		b->front = b->front - 1;
	b->arr[b->front] = a->arr[a->front];
	a->arr[a->front] = 0;
	a->front = (a->front + 1) % size;
	a->out++;
	b->in++;
	if (print)
		write(1, "pb\n", 3);
	return (ft_strdup("pb"));
}

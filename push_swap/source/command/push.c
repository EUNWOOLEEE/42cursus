/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:09 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/07 20:52:26 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_stack *a, t_stack *b, int size)
{
	if (!(b->in - b->out))
		return ;
	if (!a->front)
		a->front += size - 1;
	else
		a->front = a->front - 1;
	a->arr[a->front] = b->arr[b->front];
	b->arr[b->front] = 0;
	b->front = (b->front + 1) % size;
	b->out++;
	a->in++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, int size)
{
	if (!(a->in - a->out))
		return ;
	if (!b->front)
		b->front = size - 1;
	else
		b->front = b->front - 1;
	b->arr[b->front] = a->arr[a->front];
	a->arr[a->front] = 0;
	a->front = (a->front + 1) % size;
	a->out++;
	b->in++;
	write(1, "pb\n", 3);
}

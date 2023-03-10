/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:14 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/09 15:39:04 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack *a, int size)
{
	int	tmp;

	tmp = a->arr[a->rear];
	a->arr[a->rear] = 0;
	a->front--;
	if (a->front == -1)
		a->front = size - 1;
	a->rear--;
	if (a->rear == -1)
		a->rear = size - 1;
	a->arr[a->front] = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int size)
{
	int	tmp;

	tmp = b->arr[b->rear];
	b->arr[b->rear] = 0;
	b->front--;
	if (b->front == -1)
		b->front = size - 1;
	b->rear--;
	if (b->rear == -1)
		b->rear = size - 1;
	b->arr[b->front] = tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, int size)
{
	int	tmp;

	tmp = a->arr[a->rear];
	a->arr[a->rear] = 0;
	a->front--;
	if (a->front == -1)
		a->front = size - 1;
	a->rear--;
	if (a->rear == -1)
		a->rear = size - 1;
	a->arr[a->front] = tmp;
	tmp = b->arr[b->rear];
	b->arr[b->rear] = 0;
	b->front--;
	if (b->front == -1)
		b->front = size - 1;
	b->rear--;
	if (b->rear == -1)
		b->rear = size - 1;
	b->arr[b->front] = tmp;
	write(1, "rrr\n", 4);
}

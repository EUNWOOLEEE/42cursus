/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:17 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/07 21:02:20 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack *a, int size)
{
	int	tmp;

	tmp = a->arr[a->front];
	a->arr[a->front] = 0;
	a->front = (a->front + 1) % size;
	a->rear = (a->rear + 1) % size;
	a->arr[a->rear] = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b, int size)
{
	int	tmp;

	tmp = b->arr[b->front];
	b->arr[b->front] = 0;
	b->front = (b->front + 1) % size;
	b->rear = (b->rear + 1) % size;
	b->arr[b->rear] = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b, int size)
{
	int	tmp;

	tmp = a->arr[a->front];
	a->arr[a->front] = 0;
	a->front = (a->front + 1) % size;
	a->rear = (a->rear + 1) % size;
	a->arr[a->rear] = tmp;
	tmp = b->arr[b->front];
	b->arr[b->front] = 0;
	b->front = (b->front + 1) % size;
	b->rear = (b->rear + 1) % size;
	b->arr[b->rear] = tmp;
	write(1, "rr\n", 3);
}

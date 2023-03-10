/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/09 15:39:11 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack *a, int size)
{
	int	tmp;

	if (a->in - a->out <= 1)
		return ;
	tmp = a->arr[a->front];
	a->arr[a->front] = a->arr[(a->front + 1) % size];
	a->arr[(a->front + 1) % size] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b, int size)
{
	int	tmp;

	if (b->in - b->out <= 1)
		return ;
	tmp = b->arr[b->front];
	b->arr[b->front] = b->arr[(b->front + 1) % size];
	b->arr[(b->front + 1) % size] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, int size)
{
	int	tmp;

	if (a->in - a->out > 1)
	{
		tmp = a->arr[a->front];
		a->arr[a->front] = a->arr[(a->front + 1) % size];
		a->arr[(a->front + 1) % size] = tmp;
	}
	if (b->in - b->out > 1)
	{
		tmp = b->arr[b->front];
		b->arr[b->front] = b->arr[(b->front + 1) % size];
		b->arr[(b->front + 1) % size] = tmp;
	}
	write(1, "ss\n", 3);
}

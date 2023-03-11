/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:14 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/11 18:53:18 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*rra(t_stack *a, int size, int print)
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
	if (print)
	{
		write(1, "rra\n", 4);
		return (0);
	}
	return (ft_strdup("rra"));
}

char	*rrb(t_stack *b, int size, int print)
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
	if (print)
	{
		write(1, "rrb\n", 4);
		return (0);
	}
	return (ft_strdup("rrb"));
}

static int	set_idx(int idx, int size)
{
	idx--;
	if (idx == -1)
		idx = size - 1;
	return (idx);
}

char	*rrr(t_stack *a, t_stack *b, int size, int print)
{
	int	tmp;

	tmp = a->arr[a->rear];
	a->arr[a->rear] = 0;
	a->front = set_idx(a->front, size);
	a->rear = set_idx(a->rear, size);
	a->arr[a->front] = tmp;
	tmp = b->arr[b->rear];
	b->arr[b->rear] = 0;
	b->front = set_idx(b->front, size);
	b->rear = set_idx(b->rear, size);
	b->arr[b->front] = tmp;
	if (print)
	{
		write(1, "rrr\n", 4);
		return (0);
	}
	return (ft_strdup("rrr"));
}

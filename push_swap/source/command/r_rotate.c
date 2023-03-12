/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:14 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/12 16:35:24 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	set_idx(int idx, int size)
{
	idx--;
	if (idx == -1)
		idx = size - 1;
	return (idx);
}

char	*rra(t_stack *a, int print)
{
	int	tmp;

	tmp = a->arr[a->rear];
	a->arr[a->rear] = 0;
	a->front = set_idx(a->front, a->size);
	a->rear = set_idx(a->rear, a->size);
	a->arr[a->front] = tmp;
	if (print)
	{
		write(1, "rra\n", 4);
		return (0);
	}
	return (ft_strdup("rra"));
}

char	*rrb(t_stack *b, int print)
{
	int	tmp;
	
	tmp = b->arr[b->rear];
	b->arr[b->rear] = 0;
	b->front = set_idx(b->front, b->size);
	b->rear = set_idx(b->rear, b->size);
	b->arr[b->front] = tmp;
	if (print)
	{
		write(1, "rrb\n", 4);
		return (0);
	}
	return (ft_strdup("rrb"));
}

char	*rrr(t_stack *a, t_stack *b, int print)
{
	int	tmp;

	tmp = a->arr[a->rear];
	a->arr[a->rear] = 0;
	a->front = set_idx(a->front, a->size);
	a->rear = set_idx(a->rear, a->size);
	a->arr[a->front] = tmp;
	tmp = b->arr[b->rear];
	b->arr[b->rear] = 0;
	b->front = set_idx(b->front, b->size);
	b->rear = set_idx(b->rear, b->size);
	b->arr[b->front] = tmp;
	if (print)
	{
		write(1, "rrr\n", 4);
		return (0);
	}
	return (ft_strdup("rrr"));
}

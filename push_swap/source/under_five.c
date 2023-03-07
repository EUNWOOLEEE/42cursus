/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:25:19 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/07 20:57:22 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	under_five(t_stack *a, t_stack *b, int size)
{
	int	cnt;

	cnt = 2;
	if (size <= 3)
		while (cnt--)
			conquer_small(a, b, size);
	else if (size <= 5)
	{
		while (check_sort_a(a, size))
		{
			cnt = 2;
			devide_small(a, b, size);
			while (cnt--)
				conquer_small(a, b, size);
			combine_small(a, b, size);
		}
	}
}

void	devide_small(t_stack *a, t_stack *b, int size)
{
	int	cnt;
	int	num;

	num = size / 2;
	while (!check_sort_b(b, size))
	{
		cnt = num;
		num /= 2;
		if (!cnt)
			break ;
		while (cnt--)
		{
			if (a->arr[a->rear] < a->arr[a->front]
				&& a->arr[a->rear] < a->arr[(a->front + 1) % size])
				rra(a, size);
			else if (a->arr[(a->front + 1) % size] < a->arr[a->front])
				sa(a, size);
			pb(a, b, size);
		}
	}
}

void	conquer_small(t_stack *a, t_stack *b, int size)
{
	int	first;
	int	second;
	int	last;

	first = a->arr[a->front];
	second = a->arr[(a->front + 1) % size];
	last = a->arr[a->rear];
	if (first > second && first > last)
		ra(a, size);
	else if (second > first && second > last)
		rra(a, size);
	else if (last > first && last > second && first > second)
		sa(a, size);
	first = b->arr[b->front];
	second = b->arr[(b->front + 1) % size];
	last = b->arr[b->rear];
	if (first < second && first < last)
		rb(b, size);
	else if (second < first && second < last)
		rrb(b, size);
	else if (last < first && last < second && first < second)
		sb(b, size);
}

void	combine_small(t_stack *a, t_stack *b, int size)
{
	int	cnt;

	cnt = b->in - b->out;
	while (cnt--)
	{
		pa(a, b, size);
		conquer_small(a, b, size);
	}
}

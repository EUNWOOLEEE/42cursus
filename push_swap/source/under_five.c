/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:25:19 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/12 03:28:10 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//5개일때 조건 다시 생각해보기. 더 줄일 수 있을 것 같음

void	under_five(t_stack *a, t_stack *b)
{
	int	cnt;

	cnt = 2;
	if (a->size <= 3)
		while (cnt--)
			conquer(a, b);
	else if (a->size <= 5)
	{
		// while (check_sort_a(a)) 없어도 되나?
		{
			cnt = 2;
			devide(a, b);
			while (cnt--)
				conquer(a, b);
			combine(a, b);
		}
	}
}

void	devide(t_stack *a, t_stack *b)
{
	int	cnt;
	int	num;

	num = a->size / 2;
	while (!check_sort_b(b))
	{
		cnt = num;
		num /= 2;
		if (!cnt)
			break ;
		while (cnt--)
		{
			if (a->arr[a->rear] < a->arr[a->front]
				&& a->arr[a->rear] < a->arr[(a->front + 1) % a->size])
				rra(a, 1);
			else if (a->arr[(a->front + 1) % a->size] < a->arr[a->front])
				sa(a, 1);
			pb(a, b, 1);
		}
	}
}

void	conquer(t_stack *a, t_stack *b)
{
	int	first;
	int	second;
	int	last;

	first = a->arr[a->front];
	second = a->arr[(a->front + 1) % a->size];
	last = a->arr[a->rear];
	if (first > second && first > last)
		ra(a, 1);
	else if (second > first && second > last)
		rra(a, 1);
	else if (last > first && last > second && first > second)
		sa(a, 1);
	first = b->arr[b->front];
	second = b->arr[(b->front + 1) % a->size];
	last = b->arr[b->rear];
	if (first < second && first < last)
		rb(b, 1);
	else if (second < first && second < last)
		rrb(b, 1);
	else if (last < first && last < second && first < second)
		sb(b, 1);
}

void	combine(t_stack *a, t_stack *b)
{
	int	cnt;

	cnt = b->in - b->out;
	while (cnt--)
	{
		pa(a, b, 1);
		conquer(a, b);
	}
}
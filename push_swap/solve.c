/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:59:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/24 00:33:16 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test_print(t_struct *a, t_struct *b, int size)
{
	printf("a f: %d r: %d\n", a->front, a->rear);
	printf("b f: %d r: %d\n", b->front, b->rear);
	for(int cnt = size, i = a->front, j = b->front; cnt; cnt--)
		printf("%d  %d\n", a->arr[i++ % size], b->arr[j++ % size]);
	printf("\n");
}

void test(t_struct *a, t_struct *b, int size)
{
	test_print(a, b, size);
	// sa(a, b, size);
	// sb(a, b, size);
	// ss(a, b, size);
	// pa(a, b, size);
	// pb(a, b, size);
	// rb(a, b, size);
	// rr(a, b, size);
	// rra(a, b, size);
	// rrb(a, b, size);
	// rrr(a, b, size);
	// test_print(a, b, size);
}

void devide(t_struct *a, t_struct *b, int size)
{
	int cnt;
	int num;

	num = 1;
	if (size == 3)
	{
		pb(a, b, size);
		pb(a, b, size);
		return ;
	}
	while (!check_sort_b(b, size)) //정렬 돼있으면 a 반 더 나누기
	{
		cnt = size / (num * 2);
		while (cnt--)
			pb(a, b, size);
	}
}

void conquer(t_struct *a, t_struct *b, int size)
{
	int first;
	int second;
	int last;

	first = a->arr[a->front];
	second = a->arr[(a->front + 1) % size];
	last = a->arr[a->rear];
	if (second < first && second < last)
		sa(a, b, size);
	else if (last < first && last < second)
		rra(a, b, size);
} 

void combine(t_struct *a, t_struct *b, int size)
{
	int cnt;
	int a_first;
	int a_last;
	int b_first;

	cnt = b->in - b->out;
	while (cnt--)
	{
		a_first = a->arr[a->front];
		a_last = a->arr[a->rear];
		b_first = b->arr[b->front];
		if (b_first < a_first)
			pa(a, b, size);
		else if (b_first < a_last)
		{
			pa(a, b, size);
			sa(a, b, size);
		}
		else //b_first > a_last
		{
			pa(a, b, size);
			ra(a, b, size);
		}
	}
}

void sorting(t_struct *a, t_struct *b, int size)
{
	// test(a, b, size);
	// test_print(a, b, size);

	while (check_sort_a(a, size))
	{
		devide(a, b, size);
		conquer(a, b, size);
		combine(a, b, size);
	}
	// test_print(a, b, size);
}
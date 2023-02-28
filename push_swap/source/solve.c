/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:59:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/01 01:09:21 by eunwolee         ###   ########.fr       */
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

void move_to_b(t_struct *a, t_struct *b, int size)
{
	int i;
	int first;
	int second;
	int last;

	i = 0;
	while (i < size)
	{
		first = a->arr[a->front];
		second = a->arr[(a->front + 1) % size];
		last = a->arr[a->rear];

		if(last < first && last < second)
			rra(a, size);
		else if(second < first)
			sa(a, size);

		pb(a, b, size);

		first = b->arr[b->front];
		second = b->arr[(b->front + 1) % size];
		last = b->arr[b->rear];

		if(last > first && last > second)
			rrb(b, size);
		else if(second > first)
			sb(b, size);

		i++;
	}
}

int find_max_in_b(t_struct *b, int size)
{
	int max_idx;
	int max;
	int cur;
	int cnt;
	int idx;

	max = 0;
	cnt = b->in - b->out;
	idx = b->arr[b->front];

	while (cnt--)
	{
		cur = b->arr[idx % size];
		if (max < cur)
		{
			max = cur;
			max_idx = idx;
		}
		idx++;
	}
	return max_idx;
}

int get_optimum_idx(t_struct *a, t_struct *b, int size, int max_idx)
{
	int idx;
	int cnt;
	int num;

	idx = a->front;
	cnt = a->in - a->out;
	num = b->arr[max_idx];

	while (cnt--)
	{
		if (a->arr[idx] < num && num < a->arr[(idx + 1) % size])
			return idx;
		idx++;
	}
	return idx;
}

void go_to_a(t_struct *a, t_struct *b, int size, int idx_a, int idx_b)
{
	int cnt_a;
	int cnt_b;

	cnt_a = idx_a - a->front;
	cnt_b = idx_b - b->front;
	//pa 하기 전에 a는 b가 와야 할 위치로, b는 이동할 숫자를 top으로 옮기기 위해 회전시켜야 함. 가장 적은 횟수 찾기(r 할지 rr할지, ra와 rb가 겹치면 rr로 처리하기 등)
}

void sorting(t_struct *a, t_struct *b, int size)
{
	test_print(a, b, size);

	int cnt;
	int max_idx;
	int idx;

	cnt = 2;
	if(size <= 3)
		while (cnt--)
			conquer_small(a, b, size);
	else if(size <= 5)
		while (check_sort_a(a, size))
		{
			cnt = 2;
			devide_small(a, b, size);
			while (cnt--)
				conquer_small(a, b, size);
			combine_small(a, b, size);
		}
	else
	{
		move_to_b(a, b, size);
		test_print(a, b, size);
		cnt = size;
		while (cnt--)
		{
			max_idx = find_max_in_b(b, size);
			idx = get_optimum_idx(a, b, size, max_idx);
		}
	}
	// test_print(a, b, size);
}
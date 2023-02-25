/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:59:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/25 17:58:36 by eunwolee         ###   ########.fr       */
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

void devide_a(t_struct *a, t_struct *b, int size) //a를 반으로 나누기
{
	int cnt;
	int num;

	num = size / 2;
	while (!check_sort_b(b, size)) //정렬 돼있으면 a 반 더 나누기
	{
		cnt = num;
		num /= 2;
		if(!cnt) //다 넘겼는데 b가 정렬 돼있으면
			break;
		while (cnt--)
		{
			if(a->arr[a->rear] < a->arr[a->front] && a->arr[a->rear] < a->arr[(a->front + 1) % size])
				rra(a, size);
			else if(a->arr[(a->front + 1) % size] < a->arr[a->front])
				sa(a, size);
			pb(a, b, size);
		}
	}
}

void devide_b(t_struct *a, t_struct *b, int size) //b를 반으로 나누기
{
	int cnt;
	int num;

	num = size / 2;
	while (!check_sort_a(a, size)) //정렬 돼있으면 b 반 더 나누기
	{
		cnt = num;
		num /= 2;
		if(!cnt) //다 넘겼는데 a가 정렬 돼있으면
			break;
		while (cnt--)
		{
			if(b->arr[b->rear] > b->arr[b->front] && b->arr[b->rear] > b->arr[(b->front + 1) % size])
				rrb(b, size);
			else if(b->arr[(b->front + 1) % size] > b->arr[b->front])
				sb(b, size);
			pa(a, b, size);
		}
	}
}

void conquer(t_struct *a, t_struct *b, int size)
{
	int first;
	int second;
	int last;

	//3개 조건을 주지 않아도 되는 이유. 조건을 걸면 안되는게 맞음. 왜 조건 없이도 되는지 테스트해서 정리하기
	first = a->arr[a->front];
	second = a->arr[(a->front + 1) % size];
	last = a->arr[a->rear];
	if (first > second && first > last) //3 1 2, 3 2 1
		ra(a, size);
	else if (second > first && second > last) //1 3 2, 2 3 1
		rra(a, size);
	else if (last > first && last > second && first > second) //2 1 3
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

void combine_a(t_struct *a, t_struct *b, int size) //a로 합치기
{
	int cnt;

	cnt = b->in - b->out;
	while (cnt--)
	{
		pa(a, b, size);
		conquer(a, b, size);
	}
}

void combine_b(t_struct *a, t_struct *b, int size) //b로 합치기
{
	int cnt;

	cnt = a->in - a->out;
	while (cnt--)
	{
		pb(a, b, size);
		conquer(a, b, size);
	}
}

void sorting(t_struct *a, t_struct *b, int size)
{
	// test(a, b, size);
	// test_print(a, b, size);

	int cnt;

	cnt = 2;
	if(size == 3)
		while (cnt--)
			conquer(a, b, size);
	else if(size <= 5)
		while (check_sort_a(a, size))
		{
			cnt = 2;
			devide_a(a, b, size);
			while (cnt--)
				conquer(a, b, size);
			combine_a(a, b, size);
		}
	else
		while (check_sort_a(a, size))
		{
			cnt = 2;
			devide_a(a, b, size);
			while (cnt--)
				conquer(a, b, size);
			combine_b(a, b, size);

			cnt = 2;
			devide_b(a, b, size);
			while (cnt--)
				conquer(a, b, size);
			combine_a(a, b, size);
		}
	test_print(a, b, size);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:59:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/23 18:05:53 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test_print(t_struct *a, t_struct *b, int size)
{
	printf("a %d %d\n", a->front, a->rear);
	printf("b %d %d\n", b->front, b->rear);
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
	pb(a, b, size);
	pb(a, b, size);
	pb(a, b, size);
	pb(a, b, size);
	pb(a, b, size);
	test_print(a, b, size);

	pa(a, b, size);
	pa(a, b, size);
	pa(a, b, size);
	test_print(a, b, size);

	rr(a, b, size);
	rr(a, b, size);
	test_print(a, b, size);

	// rb(a, b, size);
	// rr(a, b, size);
	// rra(a, b, size);
	// rrb(a, b, size);
	// rrr(a, b, size);
	// test_print(a, b, size);
}

void sorting(t_struct *a, t_struct *b)
{
	int size;

	size = a->rear;
	a->in = size;
	a->rear -= 1;
	b->rear = -1;

	test(a, b, size);

	// if(check_sort(a, a_idx, size));
}
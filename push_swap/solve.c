/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:59:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/21 00:27:12 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test(int *a, int *b, int *a_idx, int *b_idx, int size)
{
	// sa(a, b, a_idx, b_idx, size);
	// sb(a, b, a_idx, b_idx, size);
	// ss(a, b, a_idx, b_idx, size);
	// pa(a, b, a_idx, b_idx, size);
	// pb(a, b, a_idx, b_idx, size);
	// ra(a, b, a_idx, b_idx, size);
	// rb(a, b, a_idx, b_idx, size);
	// rr(a, b, a_idx, b_idx, size);
	// rra(a, b, a_idx, b_idx, size);
	// rrb(a, b, a_idx, b_idx, size);
	// rrr(a, b, a_idx, b_idx, size);

	for(int i = a_idx[0], j = b_idx[0], cnt = size; cnt ; cnt--)
		printf("%d  %d\n", a[i++ % size], b[j++ % size]);
	
	printf("\ncheck_sort: %d\n", check_sort(a, a_idx, size));
}

void sorting(int *a, int *b, int *a_idx, int *b_idx)
{
	int size;

	size = a_idx[1];
	a_idx[1] -= 1;

	test(a, b, a_idx, b_idx, size);

	// if(check_sort(a, a_idx, size));
}

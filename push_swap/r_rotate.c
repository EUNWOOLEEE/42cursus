/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:14 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/20 23:55:12 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//스택의 마지막 원소는 맨 첫 번째 원소가 됨

void rra(int *a, int *b, int *a_idx, int *b_idx, int size) //a의 원소를 한 칸씩 아래로 옮김
{
	int tmp;

	tmp = a_idx[0] - 1;
	if(tmp < 0)
		tmp *= -1;
	a_idx[0] = tmp % size;

	tmp = a_idx[1] - 1;
	if(tmp < 0)
		tmp *= -1;
	a_idx[1] = tmp % size;
}

void rrb(int *a, int *b, int *a_idx, int *b_idx, int size) //b의 원소를 한 칸씩 아래로 옮김
{
	int tmp;

	tmp = b_idx[0] - 1;
	if(tmp < 0)
		tmp *= -1;
	b_idx[0] = tmp % size;

	tmp = b_idx[1] - 1;
	if(tmp < 0)
		tmp *= -1;
	b_idx[1] = tmp % size;
}

void rrr(int *a, int *b, int *a_idx, int *b_idx, int size) //rra와 rrb를 동시에 수행
{
	rra(a, b, a_idx, b_idx, size);
	rrb(a, b, a_idx, b_idx, size);
}
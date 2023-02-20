/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:17 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/20 23:51:59 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//스택의 첫번째 원소는 맨 마지막 원소가 됨

void ra(int *a, int *b, int *a_idx, int *b_idx, int size) //a의 원소를 한 칸씩 위로 옮김
{
	a_idx[0] = (a_idx[0] + 1) % size;
	a_idx[1] = (a_idx[1] + 1) % size;
}

void rb(int *a, int *b, int *a_idx, int *b_idx, int size) //b의 원소를 한 칸씩 위로 옮김
{
	b_idx[0] = (b_idx[0] + 1) % size;
	b_idx[1] = (b_idx[1] + 1) % size;
}

void rr(int *a, int *b, int *a_idx, int *b_idx, int size) //ra와 rb를 동시에 수행
{
	ra(a, b, a_idx, b_idx, size);
	rb(a, b, a_idx, b_idx, size);
}
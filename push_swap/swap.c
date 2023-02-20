/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/20 23:57:38 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않음

void sa(int *a, int *b, int *a_idx, int *b_idx, int size) //a의 top에 위치한 두 개의 원소의 순서를 맞바꿈
{
	int tmp;

	if(count_num(a_idx[0], a_idx[1]) <= 1)
		return ;

	tmp = a[a_idx[0]];
	a[a_idx[0]] = a[a_idx[0] + 1];
	a[a_idx[0] + 1] = tmp;
}

void sb(int *a, int *b, int *a_idx, int *b_idx, int size) //b의 top에 위치한 두 개의 원소의 순서를 맞바꿈
{
	int tmp;

	if(count_num(b_idx[0], b_idx[1]) <= 1)
		return ;

	tmp = b[a_idx[0]];
	b[b_idx[0]] = b[b_idx[0] + 1];
	b[b_idx[0] + 1] = tmp;
}

void ss(int *a, int *b, int *a_idx, int *b_idx, int size) //sa와 sb를 동시에 수행
{
	sa(a, b, a_idx, b_idx, size);
	sb(a, b, a_idx, b_idx, size);
}
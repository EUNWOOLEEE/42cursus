/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/06 21:36:57 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않음

void sa(t_stack *a, int size) //a의 top에 위치한 두 개의 원소의 순서를 맞바꿈
{
	int tmp;

	if(a->in - a->out <= 1)
		return ;

	tmp = a->arr[a->front];
	a->arr[a->front] = a->arr[(a->front + 1) % size];
	a->arr[(a->front + 1) % size] = tmp;
	write(1, "sa\n", 3);
}

void sb(t_stack *b, int size) //b의 top에 위치한 두 개의 원소의 순서를 맞바꿈
{
	int tmp;

	if(b->in - b->out <= 1)
		return ;

	tmp = b->arr[b->front];
	b->arr[b->front] = b->arr[(b->front + 1) % size];
	b->arr[(b->front + 1) % size] = tmp;
	write(1, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b, int size) //sa와 sb를 동시에 수행
{
	int tmp;

	if(a->in - a->out > 1)
	{
		tmp = a->arr[a->front];
		a->arr[a->front] = a->arr[(a->front + 1) % size];
		a->arr[(a->front + 1) % size] = tmp;
	}

	if(b->in - b->out > 1)
	{
		tmp = b->arr[b->front];
		b->arr[b->front] = b->arr[(b->front + 1) % size];
		b->arr[(b->front + 1) % size] = tmp;
	}
	write(1, "ss\n", 3);
}
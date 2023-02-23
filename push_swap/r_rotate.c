/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:14 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/23 15:29:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//스택의 마지막 원소는 맨 첫 번째 원소가 됨

void rra(t_struct *a, t_struct *b, int size) //a의 원소를 한 칸씩 아래로 옮김
{
	int tmp;

	tmp = a->arr[a->rear];
	a->arr[a->rear] = 0;
	a->front--;
	if(a->front == -1)
		a->front = size - 1;
	a->rear--;
	if(a->rear == -1)
		a->rear = size - 1;
	a->arr[a->front] = tmp;
}

void rrb(t_struct *a, t_struct *b, int size) //b의 원소를 한 칸씩 아래로 옮김
{
	int tmp;

	tmp = b->arr[b->rear];
	b->arr[b->rear] = 0;
	b->front--;
	if(b->front == -1)
		b->front = size - 1;
	b->rear--;
	if(b->rear == -1)
		b->rear = size - 1;
	b->arr[b->front] = tmp;
}

void rrr(t_struct *a, t_struct *b, int size) //rra와 rrb를 동시에 수행
{
	rra(a, b, size);
	rrb(a, b, size);
}
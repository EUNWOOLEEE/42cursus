/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:17 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/23 15:13:27 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//스택의 첫번째 원소는 맨 마지막 원소가 됨

void ra(t_struct *a, t_struct *b, int size) //a의 원소를 한 칸씩 위로 옮김
{
	int tmp;

	tmp = a->arr[a->front];
	a->arr[a->front] = 0;
	a->front = (a->front + 1) % size;
	a->rear = (a->rear + 1) % size;
	a->arr[a->rear] = tmp;
}

void rb(t_struct *a, t_struct *b, int size) //b의 원소를 한 칸씩 위로 옮김
{
	int tmp;

	tmp = b->arr[b->front];
	b->arr[b->front] = 0;
	b->front = (b->front + 1) % size;
	b->rear = (b->rear + 1) % size;
	b->arr[b->rear] = tmp;
}

void rr(t_struct *a, t_struct *b, int size) //ra와 rb를 동시에 수행
{
	ra(a, b, size);
	rb(a, b, size);
}
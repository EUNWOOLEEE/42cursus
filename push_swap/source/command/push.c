/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:09 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/07 17:06:48 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//비어있을 경우(옮길 원소가 없을 경우)에는 아무 동작도 하지 않음

void	pa(t_stack *a, t_stack *b, int size) //b의 top에 위치한 원소 한 개를 a의 top으로 옮김
{
	if (!(b->in - b->out))
		return ;
	if (!a->front)
		a->front += size - 1;
	else
		a->front = a->front - 1;
	a->arr[a->front] = b->arr[b->front];
	b->arr[b->front] = 0;
	b->front = (b->front + 1) % size;
	b->out++;
	a->in++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, int size) //a의 top에 위치한 원소 한 개를 b의 top으로 옮김
{
	if (!(a->in - a->out))
		return ;
	if (!b->in) //이거 없애면 왜 안됐더라?
		b->front = 0;
	else if (!b->front)
		b->front = size - 1;
	else
		b->front = b->front - 1;
	b->arr[b->front] = a->arr[a->front];
	a->arr[a->front] = 0;
	a->front = (a->front + 1) % size;
	a->out++;
	b->in++;
	write(1, "pb\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:13:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/24 19:29:32 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_num(int in, int out)
{
	return (in - out);
}

int check_sort_a(t_struct *a, int size) //a가 오름차순으로 정렬 돼있는지 확인
{
	int front;
	int num;
	int pre;

	front = a->front;
	num = size;
	pre = a->arr[front++ % size];
	while (--num)
	{
		if(pre > a->arr[front % size])
			return (-1);
		pre = a->arr[front++ % size];
	}
	return (0);
}

int check_sort_b(t_struct *b, int size) //b가 내림차순으로 정렬 돼있는지 확인
{
	int front;
	int num;
	int pre;

	front = b->front;
	num = b->in - b->out;
	pre = b->arr[front++ % size];
	if (!num) // b가 비어있을 때
		return (0);
	while (--num)
	{
		if(pre < b->arr[front % size])
			return (-1);
		pre = b->arr[front++ % size];
	}
	return (0);
}

int error_out()
{
	ft_putstr_fd("Error\n", 1);
	return (0);
}
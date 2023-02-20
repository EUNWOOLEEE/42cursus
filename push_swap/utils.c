/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:13:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/21 00:07:10 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_num(int front, int rear)
{
	int n;

	n = front - rear;
	if(n < 0)
		n *= -1;
	return (n);
}

int check_sort(int *a, int *a_idx, int size)
{
	int front;
	int num;
	int pre;

	front = a_idx[0];
	num = size;
	pre = a[front++ % size];
	while (--num)
	{
		if(pre > a[front % size])
			return (-1);
		pre = a[front++ % size];
	}
	return (0);
}

int error_out()
{
	ft_putstr_fd("Error\n", 1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:13:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/23 18:00:14 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sort(t_struct *a, int size)
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

int error_out()
{
	ft_putstr_fd("Error\n", 1);
	return (0);
}
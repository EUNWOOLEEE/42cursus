/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:13:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/07 20:52:07 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	free_n_print_out(int flag, void *a, void *b)
{
	if (flag == 1 || flag == 3 || flag == 4)
	{
		free(a);
		free(b);
	}
	if (flag == 2)
		free(a);
	if (flag == 1 || flag == 5)
		ft_putstr_fd("Error\n", 1);
	if (flag == 3 || flag == 5)
		return (-1);
	return (0);
}

int	check_sort_a(t_stack *a, int size)
{
	int	front;
	int	num;
	int	pre;

	front = a->front;
	num = size;
	pre = a->arr[front++ % size];
	while (--num)
	{
		if (pre > a->arr[front % size])
			return (-1);
		pre = a->arr[front++ % size];
	}
	return (0);
}

int	check_sort_b(t_stack *b, int size)
{
	int	front;
	int	num;
	int	pre;

	front = b->front;
	num = b->in - b->out;
	pre = b->arr[front++ % size];
	if (!num)
		return (0);
	while (--num)
	{
		if (pre < b->arr[front % size])
			return (-1);
		pre = b->arr[front++ % size];
	}
	return (0);
}

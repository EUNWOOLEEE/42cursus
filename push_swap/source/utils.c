/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:13:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/12 00:49:18 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_cmd(t_list *head)
{
	while (head)
	{
		ft_putstr_fd(head->cmd, 1);
		write(1, "\n", 1);
		head = head->next;
	}
}

int	abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	free_n_print_out(int flag, int print, void *a, void *b)
{
	if (flag == 1 || flag == 2)
	{
		if (a)
			free(a);
		if (b)
			free(b);
	}
	if (print == 1)
		ft_putstr_fd("Error\n", 1);
	if (flag == 2)
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

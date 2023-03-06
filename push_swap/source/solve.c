/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:59:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/06 19:10:43 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void get_min_num(t_struct *a, int size)
{
	int idx;
	int cnt;
	
	idx = a->front;
	cnt = a->in - a->out;
	a->min = INT_MAX;
	while (cnt--)
	{
		if (a->min > a->arr[idx])
		{
			a->min = a->arr[idx];
			a->min_idx = idx;
		}
		idx = (idx + 1) % size;
	}
}

int greedy(t_struct *a, t_struct *b, t_cmd *cmd, int size)
{
	int cnt;
	
	if (move_to_b(a, b, size) == -1)
		return (-1);
	// test_print(a, b, size);

	cnt = size;
	while (cnt--)
	{
		if (find_opt_num_in_b(a, b, size, cmd) == -1)
			return (-1);
		go_to_a(a, b, size, cmd);
		get_min_num(a, size);
		// test_print(a, b, size);
	}
	if (abs(a->min_idx - a->front) <= abs(a->min_idx - a->rear))
		while (a->arr[a->front] != a->min)
			ra(a, size);
	else
		while (a->arr[a->front] != a->min)
			rra(a, size);
	return (free_n_print_out(2, cmd, 0));
}

int sorting(t_struct *a, t_struct *b, int size)
{
	// test_print(a, b, size);
	t_cmd *cmd;

	if (size <= 5)
		under_five(a, b, size);
	else
	{
		cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
		if (!cmd)
			return (-1);
		greedy(a, b, cmd, size);
	}
	// test_print(a, b, size);
	return (0);
}
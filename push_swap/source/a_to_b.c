/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:03:27 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/07 15:03:42 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_arr(int *arr, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

t_fivot *get_min_and_fivot_num(t_stack *a, int size)
{
	int *arr;
	t_fivot *fivot;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	ft_memmove(arr, a->arr, sizeof(int) * size);
	sort_arr(arr, size);
	fivot = (t_fivot *)ft_calloc(1, sizeof(t_fivot));
	if (!fivot)
	{
		free (arr);
		return (0);
	}
	fivot->one_third = arr[size / 3];
	fivot->two_third = arr[size / 3 * 2];
	free(arr);
	return fivot;
}

int move_to_b(t_stack *a, t_stack *b, int size)
{
	int cnt;
	t_fivot *fivot;

	cnt = size;
	fivot = get_min_and_fivot_num(a, size);
	if (!fivot)
		return (-1);
	get_min_num(a, size);
	while (cnt--)
	{
		if (a->arr[a->front] < fivot->two_third)
		{
			pb(a, b, size);
			if (b->arr[b->front] < fivot->one_third)
				rb(b, size);
		}
		else
			ra(a, size);
	}
	cnt = a->in - a->out;
	while (cnt--)
		pb(a, b, size);
	return (free_n_print_out(2, fivot, 0));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:03:27 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/06 19:13:41 by eunwolee         ###   ########.fr       */
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

t_num *get_min_and_fivot_num(t_struct *a, int size)
{
	int *arr;
	t_num *nums;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	ft_memmove(arr, a->arr, sizeof(int) * size);
	nums = (t_num *)ft_calloc(1, sizeof(t_num));
	if (!nums)
	{
		free (arr);
		return (0);
	}
	
	nums->one_third = arr[size / 3 - 1];
	nums->two_third = arr[size / 3 * 2 - 1];
	free(arr);
	return nums;
}

int move_to_b(t_struct *a, t_struct *b, int size)
{
	int cnt;
	t_num *nums;

	cnt = size;
	nums = get_min_and_fivot_num(a, size);
	if (!nums)
		return (-1);
	get_min_num(a, size);
	while (cnt--)
	{
		if (a->arr[a->front] <= nums->two_third)
			pb(a, b, size);
		if (a->arr[a->front] <= nums->one_third)
			rb(b, size);
		else
			ra(a, size);
	}
	cnt = a->in - a->out;
	while (cnt--)
		pb(a, b, size);
	return (free_n_print_out(2, nums, 0));
}
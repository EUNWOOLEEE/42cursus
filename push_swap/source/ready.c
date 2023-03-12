/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:03:27 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/12 18:51:45 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_arr(int *arr, int size);

t_pivot	*get_pivots(t_stack *a)
{
	int		*arr;
	t_pivot	*pivot;

	arr = (int *)malloc(sizeof(int) * a->size);
	if (!arr)
		return (0);
	pivot = (t_pivot *)ft_calloc(1, sizeof(t_pivot));
	if (!pivot)
	{
		free (arr);
		return (0);
	}
	ft_memmove(arr, a->arr, sizeof(int) * a->size);
	sort_arr(arr, a->size);
	pivot->one_third = arr[a->size / 3];
	pivot->two_third = arr[a->size / 3 * 2];
	free (arr);
	return (pivot);
}

int	move_to_b(t_stack *a, t_stack *b, t_pivot *pivot)
{
	int	cnt;

	cnt = a->size;
	while (cnt--)
	{
		if (a->arr[a->front] < pivot->two_third)
		{
			pb(a, b, 1);
			if (b->arr[b->front] < pivot->one_third
				&& a->arr[a->front] >= pivot->two_third)
				rr(a, b, 1);
			else if (b->arr[b->front] < pivot->one_third)
				rb(b, 1);
		}
		else if (a->arr[a->front] >= pivot->two_third)
			ra(a, 1);
	}
	cnt = a->in - a->out;
	while (cnt--)
		pb(a, b, 1);
	return (0);
}

void	get_min_num(t_stack *a)
{
	int	idx;
	int	cnt;

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
		idx = (idx + 1) % a->size;
	}
}

static void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

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

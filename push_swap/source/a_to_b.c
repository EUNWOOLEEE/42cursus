/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:03:27 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/11 00:13:34 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_arr(int *arr, int size)
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

t_fivot	*get_min_and_fivot_num(t_stack *a, int size)
{
	int		*arr;
	t_fivot	*fivot;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	fivot = (t_fivot *)ft_calloc(1, sizeof(t_fivot));
	if (!fivot)
	{
		free (arr);
		return (0);
	}
	ft_memmove(arr, a->arr, sizeof(int) * size);
	sort_arr(arr, size);
	fivot->one_third = arr[size / 3];
	fivot->two_third = arr[size / 3 * 2];
	free (arr);
	return (fivot);
}

int	move_to_b(t_stack *a, t_stack *b, int size, t_fivot *fivot)
{
	int		cnt;

	cnt = size;

	while (cnt--)
	{
		if (a->arr[a->front] < fivot->two_third)
		{
			pb(a, b, size, 1);
			if (b->arr[b->front] < fivot->one_third
				&& a->arr[a->front] >= fivot->two_third)
				rr(a, b, size, 1);
			else if (b->arr[b->front] < fivot->one_third)
				rb(b, size, 1);
		}
		else if (a->arr[a->front] >= fivot->two_third)
			ra(a, size, 1);
	}
	cnt = a->in - a->out;
	while (cnt--)
		pb(a, b, size, 1);
	return (0);
}

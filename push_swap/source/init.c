/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:59:09 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/12 01:28:48 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	init_stack(t_stack *a, t_stack *b, char **argv)
{
	a->size = check_valid(argv);
	if (a->size <= 0)
		return (-1);
	a->arr = (int *)ft_calloc(a->size, sizeof(int));
	b->arr = (int *)ft_calloc(a->size, sizeof(int));
	if (!a->arr || !b->arr)
		return (-1);
	if (parsing(a, argv) == -1)
		return (free_n_print_out(1, 0, a->arr, b->arr));
	a->rear = a->size - 1;
	b->rear = a->size - 1;
	b->size = a->size;
	a->in = a->size;
	a->min = INT_MAX;
	return (a->size);
}

int	check_valid(char **argv)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-')
				&& ft_isdigit(argv[i][j + 1]))
				j++;
			while (ft_isdigit(argv[i][j]))
				j++;
			cnt++;
			if (argv[i][j] == ' ')
				j++;
			else if (argv[i][j] != '\0')
				return (-1);
		}
		i++;
	}
	return (cnt);
}

int	check_overlap(int *a, int cnt, int num)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		if (a[i] == num)
			return (-1);
		i++;
	}
	return (0);
}

int	parsing(t_stack *a, char **argv)
{
	int			i;
	int			j;
	int			idx;
	long long	num;

	i = 1;
	idx = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			num = ft_atoi(&argv[i][j]);
			if (INT_MIN > num || num > INT_MAX
				|| check_overlap(a->arr, idx, (int)num) == -1)
				return (-1);
			a->arr[idx++] = (int)num;
			while (argv[i][j] == '+' || argv[i][j] == ' ')
				j++;
			j += ft_cnt_digit((int)num);
		}
		i++;
	}
	return (0);
}

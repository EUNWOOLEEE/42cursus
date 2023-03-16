/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:59:09 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/14 19:54:49 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_valid(char **argv);
static int	check_cnt(char *str, int *cnt_num, int *cnt_space, int idx);
static int	check_overlap(int *a, int cnt, int num);
static int	parsing(t_stack *a, char **argv);

int	init_stack(t_stack *a, t_stack *b, char **argv)
{
	a->size = check_valid(argv);
	if (a->size == -1)
		return (-1);
	a->arr = (int *)ft_calloc(a->size, sizeof(int));
	b->arr = (int *)ft_calloc(a->size, sizeof(int));
	if (!a->arr || !b->arr)
		return (-1);
	if (parsing(a, argv) == -1)
		return (free_n_print_out(2, 0, a->arr, b->arr));
	a->rear = a->size - 1;
	b->rear = a->size - 1;
	b->size = a->size;
	a->in = a->size;
	a->min = INT_MAX;
	return (a->size);
}

static int	check_valid(char **argv)
{
	int	i;
	int	j;
	int	res;
	int	cnt_num;
	int	cnt_space;

	res = 0;
	i = 1;
	while (argv[i])
	{
		cnt_num = 0;
		cnt_space = 0;
		j = 0;
		if (check_cnt(argv[i], &cnt_num, &cnt_space, 0) == -1)
			return (-1);
		if (cnt_space && cnt_num - 1 != cnt_space)
			return (-1);
		res += cnt_num;
		i++;
	}
	return (res);
}

static int	check_cnt(char *str, int *cnt_num, int *cnt_space, int idx)
{
	while (str[idx])
	{
		if (ft_issign(str[idx]) && ft_isdigit(str[idx + 1]))
		{
			if (str[idx + 1] == '0')
				return (-1);
			idx++;
		}
		if (ft_isdigit(str[idx]))
		{
			while (ft_isdigit(str[idx]))
				idx++;
			*cnt_num += 1;
		}
		if (str[idx] == ' ')
		{
			idx++;
			*cnt_space += 1;
		}
		else if (str[idx] != '\0')
			return (-1);
	}
	return (0);
}

static int	check_overlap(int *a, int cnt, int num)
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

static int	parsing(t_stack *a, char **argv)
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

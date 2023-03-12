/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:25:19 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/12 16:39:31 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_first_second(t_stack *a);
static void	devide(t_stack *a, t_stack *b);
static void	conquer(t_stack *a, t_stack *b, t_cmd *cmd);
static void	act_cmd(t_stack *a, t_stack *b, t_cmd *cmd);

void	under_five(t_stack *a, t_stack *b, t_cmd *cmd)
{
	int	cnt;

	cnt = 2;
	if (a->size <= 3)
		while (cnt--)
		{
			conquer(a, b, cmd);
			act_cmd(a, b, cmd);
		}
	else if (a->size <= 5)
	{
		devide(a, b);
		if (a->out)
		{
			while (cnt--)
				conquer(a, b, cmd);
			cnt = b->in - b->out;
			while (cnt--)
			{
				pa(a, b, 1);
				conquer(a, b, cmd);
			}
		}
	}
}

static int	check_first_second(t_stack *a)
{
	int	i;

	i = 1;
	while (++i < a->size)
		if (a->arr[i] > a->arr[0] || a->arr[i] > a->arr[1])
			return (-1);
	return (0);
}

static void	devide(t_stack *a, t_stack *b)
{
	int	cnt;

	cnt = 2;
	if (!check_first_second(a))
	{
		if (a->arr[0] > a->arr[1])
			sa(a, 1);
		ra(a, 1);
		ra(a, 1);
	}
	while (cnt-- && check_sort_a(a) == -1)
	{
		if (a->arr[a->rear] < a->arr[a->front]
			&& a->arr[a->rear] < a->arr[(a->front + 1) % a->size])
			rra(a, 1);
		else if (a->arr[(a->front + 1) % a->size] < a->arr[a->front])
			sa(a, 1);
		pb(a, b, 1);
	}
}

static void	conquer(t_stack *a, t_stack *b, t_cmd *cmd)
{
	int	first;
	int	second;
	int	last;

	first = a->arr[a->front];
	second = a->arr[(a->front + 1) % a->size];
	last = a->arr[a->rear];
	if (first > second && first > last)
		cmd->ra++;
	else if (second > first && second > last)
		cmd->rra++;
	else if (last > first && last > second && first > second)
		cmd->sa++;
	first = b->arr[b->front];
	last = b->arr[b->rear];
	if (first < last)
	{
		cmd->sb++;
		cmd->rb++;
	}
	act_cmd(a, b, cmd);
	ft_memset(cmd, 0, sizeof(t_cmd));
}

static void	act_cmd(t_stack *a, t_stack *b, t_cmd *cmd)
{
	if (cmd->sa && cmd->sb)
	{
		ss(a, b, 1);
		cmd->sb--;
	}
	else if (cmd->ra && cmd->rb)
	{
		rr(a, b, 1);
		cmd->rb--;
	}
	else if (cmd->sa)
		sa(a, 1);
	else if (cmd->ra)
		ra(a, 1);
	else if (cmd->rra)
		rra(a, 1);
	if (cmd->sb && cmd->rb)
		sb(b, 1);
}

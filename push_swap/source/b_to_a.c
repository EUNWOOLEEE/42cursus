/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:56:19 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/07 20:19:40 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_opt_idx_in_a(t_stack *a, t_stack *b, int size, t_cmd *tmp)
{
	int	num;

	if (!(a->in - a->out))
	{
		tmp->idx_a = a->front;
		return ;
	}
	num = b->arr[tmp->idx_b];
	if (a->min > num)
	{
		if (a->arr[a->front] < a->arr[a->rear])
			tmp->idx_a = a->front;
		else
			tmp->idx_a = a->min_idx;
		return ;
	}
	else
		max_in_less_than_num(a, b, size, tmp);
}

void	max_in_less_than_num(t_stack *a, t_stack *b, int size, t_cmd *tmp)
{
	int	idx;
	int	cnt;
	int	num;
	int	opt_idx;

	idx = a->front;
	cnt = a->in - a->out;
	num = b->arr[tmp->idx_b];
	opt_idx = a->min_idx;
	while (cnt--)
	{
		if (a->arr[opt_idx] < a->arr[idx] && a->arr[idx] < num)
			opt_idx = idx;
		idx = (idx + 1) % size;
	}
	if (opt_idx == a->rear)
		tmp->idx_a = a->front;
	else
		tmp->idx_a = (opt_idx + 1) % size;
}

int	get_cmd_cnt(t_stack *a, t_stack *b, t_cmd *cmd)
{
	if (abs(cmd->idx_a - a->front) <= abs(cmd->idx_a - a->rear))
		cmd->ra = abs(cmd->idx_a - a->front);
	else
		cmd->rra = abs(cmd->idx_a - a->rear) + 1;
	if (abs(cmd->idx_b - b->front) <= abs(cmd->idx_b - b->rear))
		cmd->rb = abs(cmd->idx_b - b->front);
	else
		cmd->rrb = abs(cmd->idx_b - b->rear) + 1;
	return (abs(cmd->ra - cmd->rb) + abs(cmd->rra - cmd->rrb));
}

int	find_opt_num_in_b(t_stack *a, t_stack *b, int size, t_cmd *cmd)
{
	int		cnt;
	t_mc	mc;
	t_cmd	*tmp;

	mc.min_cnt = INT_MAX;
	mc.cur_idx = b->front;
	cnt = b->in - b->out;
	tmp = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (!tmp)
		return (-1);
	while (cnt--)
	{
		ft_memset(tmp, 0, sizeof(t_cmd));
		tmp->idx_b = mc.cur_idx;
		get_opt_idx_in_a(a, b, size, tmp);
		mc.cur_cnt = get_cmd_cnt(a, b, tmp);
		if (mc.min_cnt >= mc.cur_cnt && b->arr[mc.min_idx] < b->arr[mc.cur_idx])
		{
			mc.min_idx = mc.cur_idx;
			mc.min_cnt = mc.cur_cnt;
			ft_memmove(cmd, tmp, sizeof(t_cmd));
		}
		mc.cur_idx = (mc.cur_idx + 1) % size;
	}
	return (free_n_print_out(2, tmp, 0));
}

void	go_to_a(t_stack *a, t_stack *b, int size, t_cmd *cmd)
{
	while (cmd->ra && cmd->rb)
	{
		rr(a, b, size);
		cmd->ra--;
		cmd->rb--;
	}
	while (cmd->rra && cmd->rrb)
	{
		rrr(a, b, size);
		cmd->rra--;
		cmd->rrb--;
	}
	while (cmd->ra--)
		ra(a, size);
	while (cmd->rra--)
		rra(a, size);
	while (cmd->rb--)
		rb(b, size);
	while (cmd->rrb--)
		rrb(b, size);
	pa(a, b, size);
}

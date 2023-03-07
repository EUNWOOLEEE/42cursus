/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:56:19 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/07 17:20:47 by eunwolee         ###   ########.fr       */
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
	int		min[2]; //0-cnt, 1-idx
	int		cur[2];
	t_cmd	*tmp;

	min[0] = INT_MAX;
	cur[1] = b->front;
	cnt = b->in - b->out;
	tmp = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (!tmp)
		return (-1);
	while (cnt--)
	{
		memset(tmp, 0, sizeof(t_cmd));
		tmp->idx_b = cur[1];
		get_opt_idx_in_a(a, b, size, tmp);
		cur[0] = get_cmd_cnt(a, b, tmp);
		if (min[0] >= cur[0] && b->arr[min[1]] < b->arr[cur[1]])
		{
			min[1] = cur[1];
			min[0] = cur[0];
			ft_memmove(cmd, tmp, sizeof(t_cmd));
		}
		cur[1] = (cur[1] + 1) % size;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:56:19 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/06 19:27:51 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//이 함수 조건이 이상한 것 같음. 다시 생각해보기
void get_opt_idx_in_a(t_struct *a, t_struct *b, int size, t_cmd *tmp)
{
	int num;

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

void max_in_less_than_num(t_struct *a, t_struct *b, int size, t_cmd *tmp)
{
	int idx;
	int cnt;
	int num;
	int opt_idx;

	//num보다 작은 것중에 제일 큰 수 찾기
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

int get_cmd_cnt(t_struct *a, t_struct *b, t_cmd *cmd)
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

int find_opt_num_in_b(t_struct *a, t_struct *b, int size, t_cmd *cmd)
{
	int cnt;
	int idx;
	int min_cnt;
	int cur_cnt;
	t_cmd *tmp;

	min_cnt = INT_MAX;
	cnt = b->in - b->out;
	idx = b->front;
	tmp = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (!tmp)
		return (-1);
	while (cnt--)
	{
		memset(tmp, 0, sizeof(t_cmd));
		tmp->idx_b = idx;
		get_opt_idx_in_a(a, b, size, tmp);
		cur_cnt = get_cmd_cnt(a, b, tmp);
		if(min_cnt > cur_cnt)
		{
			min_cnt = cur_cnt;
			ft_memmove(cmd, tmp, sizeof(t_cmd));
		}
		idx = (idx + 1) % size;
	}
	return (free_n_print_out(2, tmp, 0));
}

void go_to_a(t_struct *a, t_struct *b, int size, t_cmd *cmd)
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
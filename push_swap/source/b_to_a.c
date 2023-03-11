/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:56:19 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/11 18:39:12 by eunwolee         ###   ########.fr       */
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

int	get_cmd_cnt(t_stack *a, t_stack *b, int size, t_cmd *cmd)
{
	int	tmp;

	if (a->front > size / 3 && cmd->idx_a < size / 3)
		tmp = cmd->idx_a + size;
	else
		tmp = cmd->idx_a;
	if (abs(tmp - a->front) <= abs(tmp - a->rear))
		cmd->ra = abs(tmp - a->front);
	else
		cmd->rra = abs(tmp - a->rear) + 1;

	if (abs(cmd->idx_b - b->front) <= abs(cmd->idx_b - b->rear))
		cmd->rb = abs(cmd->idx_b - b->front);
	else
		cmd->rrb = abs(cmd->idx_b - b->rear) + 1;
	return (abs(cmd->ra - cmd->rb) + abs(cmd->rra - cmd->rrb));
}

int	find_more_than_fivot(t_stack *b, int size, int fivot)
{
	int	cnt;
	int	idx;

	cnt = b->in - b->out;
	idx = b->front;
	while (cnt--)
	{
		if (b->arr[idx] >= fivot)
			return (1);
		idx = (idx + 1) % size;
	}
	return (0);
}

void	go_to_a(t_stack *a, t_stack *b, int size, t_cmd *cmd, t_list **head)
{
	while (cmd->ra && cmd->rb)
	{
		ft_lstadd_back(head, ft_lstnew(rr(a, b, size, 0)));
		cmd->ra--;
		cmd->rb--;
	}
	while (cmd->rra && cmd->rrb)
	{
		ft_lstadd_back(head, ft_lstnew(rrr(a, b, size, 0)));
		cmd->rra--;
		cmd->rrb--;
	}
	while (cmd->ra--)
		ft_lstadd_back(head, ft_lstnew(ra(a, size, 0)));
	while (cmd->rra--)
		ft_lstadd_back(head, ft_lstnew(rra(a, size, 0)));
	while (cmd->rb--)
		ft_lstadd_back(head, ft_lstnew(rb(b, size, 0)));
	while (cmd->rrb--)
		ft_lstadd_back(head, ft_lstnew(rrb(b, size, 0)));
	ft_lstadd_back(head, ft_lstnew(pa(a, b, size, 0)));
}

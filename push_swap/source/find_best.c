/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:10:22 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/11 01:16:53 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int set_fivot(t_stack *b, int size, t_fivot *fivot)
{
	int	fiv;
	
	if (find_more_than_fivot(b, size, fivot->two_third))
		fiv = fivot->two_third;
	else if (find_more_than_fivot(b, size, fivot->one_third))
		fiv = fivot->one_third;
	else
		fiv = INT_MIN;
	return fiv;
}

int	find_opt_num_in_b_by_fivot(t_stack *a, t_stack *b, int size, t_cmd *cmd, t_fivot *fivot)
{
	t_mc	mc;
	t_cmd	*tmp;
	int		fiv;

	mc.min_cnt = INT_MAX;
	mc.cur_idx = b->front;
	mc.cnt = b->in - b->out;
	mc.max_in_min_cnt = INT_MIN;
	tmp = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (!tmp)
		return (-1);
	fiv = set_fivot(b, size, fivot);
	while (mc.cnt--)
	{
		ft_memset(tmp, 0, sizeof(t_cmd));
		if (b->arr[mc.cur_idx] >= fiv)
		{
			tmp->idx_b = mc.cur_idx;
			get_opt_idx_in_a(a, b, size, tmp);
			mc.cur_cnt = get_cmd_cnt(a, b, tmp);
			if (mc.min_cnt >= mc.cur_cnt && mc.max_in_min_cnt < b->arr[mc.cur_idx])
			{
				mc.max_in_min_cnt = b->arr[mc.cur_idx];
				mc.min_cnt = mc.cur_cnt;
				ft_memmove(cmd, tmp, sizeof(t_cmd));
			}
		}
		mc.cur_idx = (mc.cur_idx + 1) % size;
	}
	return (free_n_print_out(2, 0, tmp, 0));
}

int	find_opt_num_in_b_by_greedy(t_stack *a, t_stack *b, int size, t_cmd *cmd)
{
	t_mc	mc;
	t_cmd	*tmp;

	mc.min_cnt = INT_MAX;
	mc.cur_idx = b->front;
	mc.cnt = b->in - b->out;
	mc.max_in_min_cnt = INT_MIN;
	tmp = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (!tmp)
		return (-1);
	while (mc.cnt--)
	{
		ft_memset(tmp, 0, sizeof(t_cmd));
		tmp->idx_b = mc.cur_idx;
		get_opt_idx_in_a(a, b, size, tmp);
		mc.cur_cnt = get_cmd_cnt(a, b, tmp);
		if (mc.min_cnt >= mc.cur_cnt && mc.max_in_min_cnt < b->arr[mc.cur_idx])
		{
			mc.max_in_min_cnt = b->arr[mc.cur_idx];
			mc.min_cnt = mc.cur_cnt;
			ft_memmove(cmd, tmp, sizeof(t_cmd));
		}
		mc.cur_idx = (mc.cur_idx + 1) % size;
	}
	return (free_n_print_out(2, 0, tmp, 0));
}
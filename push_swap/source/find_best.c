/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:10:22 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/12 16:48:26 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	set_fivot(t_stack *b, t_fivot *fivot);
static t_mc	*set_min_n_cur(t_stack *b);
static void	set_mc_n_cmd(t_stack *b, t_cmd *cmd, t_cmd *tmp, t_mc *mc);

int	find_opt_num_in_b_by_fivot(t_stack *a, t_stack *b, t_cmd *cmd, t_fivot *fivot)
{
	t_mc	*mc;
	t_cmd	*tmp;
	int		fiv;

	mc = set_min_n_cur(b);
	tmp = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (!tmp || !mc)
		return (free_n_print_out(2, 0, tmp, mc));
	fiv = set_fivot(b, fivot);
	while (mc->cnt--)
	{
		ft_memset(tmp, 0, sizeof(t_cmd));
		if (b->arr[mc->cur_idx] >= fiv)
		{
			tmp->idx_b = mc->cur_idx;
			get_opt_idx_in_a(a, b, tmp);
			mc->cur_cnt = get_cmd_cnt(a, b, tmp);
			if (mc->min_cnt >= mc->cur_cnt && mc->max_in_min_cnt < b->arr[mc->cur_idx])
				set_mc_n_cmd(b, cmd, tmp, mc);
		}
		mc->cur_idx = (mc->cur_idx + 1) % a->size;
	}
	return (free_n_print_out(1, 0, mc, tmp));
}

int	find_opt_num_in_b_by_greedy(t_stack *a, t_stack *b, t_cmd *cmd)
{
	t_mc	*mc;
	t_cmd	*tmp;

	mc = set_min_n_cur(b);
	tmp = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (!tmp || !mc)
		return (free_n_print_out(2, 0, tmp, mc));
	while (mc->cnt--)
	{
		ft_memset(tmp, 0, sizeof(t_cmd));
		tmp->idx_b = mc->cur_idx;
		get_opt_idx_in_a(a, b, tmp);
		mc->cur_cnt = get_cmd_cnt(a, b, tmp);
		if (mc->min_cnt >= mc->cur_cnt && mc->max_in_min_cnt < b->arr[mc->cur_idx])
			set_mc_n_cmd(b, cmd, tmp, mc);
		mc->cur_idx = (mc->cur_idx + 1) % a->size;
	}
	return (free_n_print_out(1, 0, mc, tmp));
}

static int	set_fivot(t_stack *b, t_fivot *fivot)
{
	int	fiv;
	
	if (find_more_than_fivot(b, fivot->two_third))
		fiv = fivot->two_third;
	else if (find_more_than_fivot(b, fivot->one_third))
		fiv = fivot->one_third;
	else
		fiv = INT_MIN;
	return (fiv);
}

static t_mc	*set_min_n_cur(t_stack *b)
{
	t_mc	*mc;
	
	mc = (t_mc *)ft_calloc(1, sizeof(t_mc));
	if (!mc)
		return (0);
	mc->min_cnt = INT_MAX;
	mc->cur_idx = b->front;
	mc->cnt = b->in - b->out;
	mc->max_in_min_cnt = INT_MIN;
	return (mc);
}

static void	set_mc_n_cmd(t_stack *b, t_cmd *cmd, t_cmd *tmp, t_mc *mc)
{
	mc->max_in_min_cnt = b->arr[mc->cur_idx];
	mc->min_cnt = mc->cur_cnt;
	ft_memmove(cmd, tmp, sizeof(t_cmd));
}

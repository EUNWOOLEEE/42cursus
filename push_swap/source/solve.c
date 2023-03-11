/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:59:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/12 02:26:25 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_min_num(t_stack *a)
{
	int	idx;
	int	cnt;

	idx = a->front;
	cnt = a->in - a->out;
	a->min = INT_MAX;
	while (cnt--)
	{
		if (a->min > a->arr[idx])
		{
			a->min = a->arr[idx];
			a->min_idx = idx;
		}
		idx = (idx + 1) % a->size;
	}
}

t_list	*solve_greedy(t_stack *a, t_stack *b, t_cmd *cmd)
{
	int		cnt;
	t_list	*head;

	cnt = a->size;
	head = 0;
	while (cnt--)
	{
		if (find_opt_num_in_b_by_greedy(a, b, cmd) == -1)
			return (0);
		go_to_a(a, b, cmd, &head);
		get_min_num(a);
	}
	if (abs(a->min_idx - a->front) <= abs(a->min_idx - a->rear))
		while (a->arr[a->front] != a->min)
			ft_lstadd_back(&head, ft_lstnew(ra(a, 0)));
	else
		while (a->arr[a->front] != a->min)
			ft_lstadd_back(&head, ft_lstnew(rra(a, 0)));
	return (head);
}

t_list	*solve_fivot(t_stack *a, t_stack *b, t_cmd *cmd, t_fivot *fivot)
{
	int		cnt;
	t_list	*head;

	cnt = a->size;
	head = 0;
	while (cnt--)
	{
		if (find_opt_num_in_b_by_fivot(a, b, cmd, fivot) == -1)
			return (0);
		go_to_a(a, b, cmd, &head);
		get_min_num(a);
	}
	if (abs(a->min_idx - a->front) <= abs(a->min_idx - a->rear))
		while (a->arr[a->front] != a->min)
			ft_lstadd_back(&head, ft_lstnew(ra(a, 0)));
	else
		while (a->arr[a->front] != a->min)
			ft_lstadd_back(&head, ft_lstnew(rra(a, 0)));
	return (head);
}

t_stack *make_tmp_stack(t_stack *src)
{
	t_stack *tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (!tmp)
		return (0);
	ft_memmove(tmp, src, sizeof(t_stack));
	tmp->arr = (int *)malloc(sizeof(int) * src->size);
	if (!tmp->arr)
	{
		free(tmp);
		return (0);
	}
	ft_memmove(tmp->arr, src->arr, sizeof(int) * src->size);
	return (tmp);
}

int	greedy(t_stack *a, t_stack *b, t_cmd *cmd, t_fivot *fivot)
{
	t_stack *a_tmp;
	t_stack *b_tmp;
	t_list	*cmd_fivot;
	t_list	*cmd_greedy;

	a_tmp = make_tmp_stack(a);
	b_tmp = make_tmp_stack(b);
	if (!a_tmp || !b_tmp)
		return (free_n_print_out(2, 0, a_tmp, b_tmp));
	cmd_fivot = solve_fivot(a_tmp, b_tmp, cmd, fivot);
	cmd_greedy = solve_greedy(a, b, cmd);
	if (ft_lstsize(cmd_fivot) <= ft_lstsize(cmd_greedy))
		print_cmd(cmd_fivot);
	else
		print_cmd(cmd_greedy);
	ft_lstclear(&cmd_fivot, free);
	ft_lstclear(&cmd_greedy, free);
	free_n_print_out(1, 0, a_tmp->arr, b_tmp->arr);
	return (free_n_print_out(1, 0, a_tmp, b_tmp));
}

int	sorting(t_stack *a, t_stack *b)
{
	t_cmd	*cmd;
	t_fivot	*fivot;

	if (a->size <= 5)
		under_five(a, b);
	else
	{
		cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
		if (!cmd)
			return (-1);
		get_min_num(a);
		fivot = get_fivot_num(a);
		if (!fivot)
			return (free_n_print_out(2, 0, cmd, 0));
		if (move_to_b(a, b, fivot) == -1)
			return (free_n_print_out(2, 0, cmd, fivot));
		if (greedy(a, b, cmd, fivot) == -1)
			return (free_n_print_out(2, 0, cmd, fivot));
		return (free_n_print_out(1, 0, cmd, fivot));
	}
	return (0);
}

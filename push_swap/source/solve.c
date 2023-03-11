/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:59:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/12 00:52:48 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_min_num(t_stack *a, int size)
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
		idx = (idx + 1) % size;
	}
}

t_list	*solve_greedy(t_stack *a, t_stack *b, t_cmd *cmd, int size)
{
	int		cnt;
	t_list	*head;

	cnt = size;
	head = 0;
	while (cnt--)
	{
		if (find_opt_num_in_b_by_greedy(a, b, size, cmd) == -1)
			return (0);
		go_to_a(a, b, size, cmd, &head);
		get_min_num(a, size);
	}
	if (abs(a->min_idx - a->front) <= abs(a->min_idx - a->rear))
		while (a->arr[a->front] != a->min)
			ft_lstadd_back(&head, ft_lstnew(ra(a, size, 0)));
	else
		while (a->arr[a->front] != a->min)
			ft_lstadd_back(&head, ft_lstnew(rra(a, size, 0)));
	return (head);
}

t_list	*solve_fivot(t_stack *a, t_stack *b, t_cmd *cmd, int size, t_fivot *fivot)
{
	int		cnt;
	t_list	*head;

	cnt = size;
	head = 0;
	while (cnt--)
	{
		if (find_opt_num_in_b_by_fivot(a, b, size, cmd, fivot) == -1)
			return (0);
		go_to_a(a, b, size, cmd, &head);
		get_min_num(a, size);
	}
	if (abs(a->min_idx - a->front) <= abs(a->min_idx - a->rear))
		while (a->arr[a->front] != a->min)
			ft_lstadd_back(&head, ft_lstnew(ra(a, size, 0)));
	else
		while (a->arr[a->front] != a->min)
			ft_lstadd_back(&head, ft_lstnew(rra(a, size, 0)));
	return (head);
}

int	greedy(t_stack *a, t_stack *b, t_cmd *cmd, int size)
{
	t_fivot	*fivot;
	t_stack *a_tmp;
	t_stack *b_tmp;
	t_list	*cmd_fivot;
	t_list	*cmd_greedy;

	a_tmp = (t_stack *)malloc(sizeof(t_stack));
	b_tmp = (t_stack *)malloc(sizeof(t_stack));
	if (!a_tmp || !b_tmp)
		return (free_n_print_out(2, 0, a_tmp, b_tmp));
	fivot = get_fivot_num(a, size);
	if (!fivot)
		return (free_n_print_out(2, 0, a_tmp, b_tmp));
	if (move_to_b(a, b, size, fivot) == -1)
	{
		free_n_print_out(2, 0, a_tmp, b_tmp);
		return (free_n_print_out(2, 0, fivot, 0));
	}
	
	ft_memmove(a_tmp, a, sizeof(t_stack));
	ft_memmove(b_tmp, b, sizeof(t_stack));

	a_tmp->arr = (int *)malloc(sizeof(size) * size);
	b_tmp->arr = (int *)malloc(sizeof(size) * size);
	if (!a_tmp->arr || !b_tmp->arr)
	{
		free(fivot);
		free_n_print_out(3, 0, a_tmp->arr, b_tmp->arr);
		return (free_n_print_out(3, 0, a_tmp, b_tmp));
	}
	
	ft_memmove(a_tmp->arr, a->arr, sizeof(int) * size);
	ft_memmove(b_tmp->arr, b->arr, sizeof(int) * size);
	
	cmd_fivot = solve_fivot(a_tmp, b_tmp, cmd, size, fivot);
	cmd_greedy = solve_greedy(a, b, cmd, size);
	free(fivot);

	if (ft_lstsize(cmd_fivot) <= ft_lstsize(cmd_greedy))
		print_cmd(cmd_fivot);
	else
		print_cmd(cmd_greedy);
	ft_lstclear(&cmd_fivot, free);
	ft_lstclear(&cmd_greedy, free);
	free_n_print_out(1, 0, a_tmp->arr, b_tmp->arr);
	return (free_n_print_out(1, 0, a_tmp, b_tmp));
}

int	sorting(t_stack *a, t_stack *b, int size)
{
	t_cmd	*cmd;

	if (size <= 5)
		under_five(a, b, size);
	else
	{
		cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
		if (!cmd)
			return (-1);
		get_min_num(a, size);
		if (greedy(a, b, cmd, size) == -1)
			return (free_n_print_out(2, 0, cmd, 0));
		return (free_n_print_out(1, 0, cmd, 0));
	}
	return (0);
}

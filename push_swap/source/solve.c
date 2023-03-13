/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:59:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/13 14:19:30 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		sorting(t_stack *a, t_stack *b, t_cmd *cmd, t_pivot *pivot);
static t_stack	*make_tmp_stack(t_stack *src);
static t_list	*solve_g(t_stack *a, t_stack *b, t_cmd *cmd);
static t_list	*solve_p(t_stack *a, t_stack *b, t_cmd *cmd, t_pivot *pivot);

int	solve(t_stack *a, t_stack *b)
{
	t_cmd	*cmd;
	t_pivot	*pivot;

	cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (-1);
	if (a->size <= 5)
		under_five(a, b, cmd);
	else
	{
		get_min_num(a);
		pivot = get_pivots(a);
		if (!pivot)
			return (free_n_print_out(2, 0, cmd, 0));
		if (move_to_b(a, b, pivot) == -1)
			return (free_n_print_out(2, 0, cmd, pivot));
		if (sorting(a, b, cmd, pivot) == -1)
			return (free_n_print_out(2, 0, cmd, pivot));
		return (free_n_print_out(1, 0, cmd, pivot));
	}
	return (free_n_print_out(1, 0, cmd, 0));
}

static int	sorting(t_stack *a, t_stack *b, t_cmd *cmd, t_pivot *pivot)
{
	t_stack	*a_tmp;
	t_stack	*b_tmp;
	t_list	*cmd_pivot;
	t_list	*cmd_greedy;

	a_tmp = make_tmp_stack(a);
	b_tmp = make_tmp_stack(b);
	if (!a_tmp || !b_tmp)
		return (free_n_print_out(2, 0, a_tmp, b_tmp));
	cmd_pivot = solve_p(a_tmp, b_tmp, cmd, pivot);
	cmd_greedy = solve_g(a, b, cmd);
	if (ft_lstsize(cmd_pivot) <= ft_lstsize(cmd_greedy))
		print_cmd(cmd_pivot);
	else
		print_cmd(cmd_greedy);
	ft_lstclear(&cmd_pivot, free);
	ft_lstclear(&cmd_greedy, free);
	free_n_print_out(1, 0, a_tmp->arr, b_tmp->arr);
	return (free_n_print_out(1, 0, a_tmp, b_tmp));
}

static t_list	*solve_g(t_stack *a, t_stack *b, t_cmd *cmd)
{
	int		cnt;
	t_list	*head;

	cnt = a->size;
	head = 0;
	while (cnt--)
	{
		if (find_opt_num_in_b_g(a, b, cmd) == -1)
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

static t_list	*solve_p(t_stack *a, t_stack *b, t_cmd *cmd, t_pivot *pivot)
{
	int		cnt;
	t_list	*head;

	cnt = a->size;
	head = 0;
	while (cnt--)
	{
		if (find_opt_num_in_b_p(a, b, cmd, pivot) == -1)
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

static t_stack	*make_tmp_stack(t_stack *src)
{
	t_stack	*tmp;

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

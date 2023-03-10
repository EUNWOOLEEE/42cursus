/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:59:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/10 22:35:05 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	test_print(t_stack *a, t_stack *b, int size)
{
	printf("a f: %d r: %d\n", a->front, a->rear);
	printf("b f: %d r: %d\n", b->front, b->rear);
	for(int cnt = size, i = a->front, j = b->front; cnt; cnt--, i++, j++)
		printf("[%d]%d  [%d]%d\n", i % size, a->arr[i % size], j % size, b->arr[j % size]);
	printf("\n");
}

void	print_cmd(t_list *head)
{
	while (head)
	{
		ft_putstr_fd(head->cmd, 1);
		head = head->next;
	}
}

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
		print_cmd(head);
		go_to_a(a, b, size, cmd, head);
		get_min_num(a, size);
		// test_print(a, b, size);
	}
	if (abs(a->min_idx - a->front) <= abs(a->min_idx - a->rear))
		ft_lstadd_back(&head, ft_lstnew(ra(a, size, 0)));
	else
		ft_lstadd_back(&head, ft_lstnew(rb(b, size, 0)));
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
		go_to_a(a, b, size, cmd, head);
		get_min_num(a, size);
	}
	if (abs(a->min_idx - a->front) <= abs(a->min_idx - a->rear))
		ft_lstadd_back(&head, ft_lstnew(ra(a, size, 0)));
	else
		ft_lstadd_back(&head, ft_lstnew(rb(b, size, 0)));
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
	fivot = get_min_and_fivot_num(a, size);
	if (!fivot)
		return (-1);
	if (move_to_b(a, b, size, fivot) == -1)
		return (free_n_print_out(4, 0, fivot, 0));
	ft_memmove(a_tmp, a, sizeof(t_stack));
	ft_memmove(b_tmp, b, sizeof(t_stack));
	//구조체 통째로 복사하면서 안에 배열 주소도 그대로 복사됨. 할당하고 따로 memmove로 복제하기
	printf("%p %p\n", a->arr, a_tmp->arr);

	cmd_fivot = solve_fivot(a_tmp, b_tmp, cmd, size, fivot);
	cmd_greedy = solve_greedy(a, b, cmd, size);

	if (ft_lstsize(cmd_fivot) <= ft_lstsize(cmd_greedy))
		print_cmd(cmd_fivot);
	else
		print_cmd(cmd_greedy);
	ft_lstclear(&cmd_fivot, free);
	ft_lstclear(&cmd_greedy, free);

	return (free_n_print_out(2, 0, fivot, 0));
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
			return (free_n_print_out(4, 0, cmd, 0));
		return (free_n_print_out(2, 0, cmd, 0));
	}
	return (0);
}

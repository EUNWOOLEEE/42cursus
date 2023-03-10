 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:21:04 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/10 18:11:01 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	act_cmd_r_rr(t_stack *a, t_stack *b, int size, char *cmd_str)
{
	if (!ft_strncmp(cmd_str, "ra\n", 3))
		ra(a, size, 0);
	else if (!ft_strncmp(cmd_str, "rb\n", 3))
		rb(b, size, 0);
	else if (!ft_strncmp(cmd_str, "rr\n", 3))
		rr(a, b, size, 0);
	else if (!ft_strncmp(cmd_str, "rra\n", 4))
		rra(a, size, 0);
	else if (!ft_strncmp(cmd_str, "rrb\n", 4))
		rrb(b, size, 0);
	else if (!ft_strncmp(cmd_str, "rrr\n", 4))
		rrr(a, b, size, 0);
	else
		return (-1);
	return (0);
}

int	act_cmd_p_s(t_stack *a, t_stack *b, int size, char *cmd_str)
{
	int	idx;

	idx = 0;
	if (!ft_strncmp(cmd_str, "pa\n", 3))
		pa(a, b, size, 0);
	else if (!ft_strncmp(cmd_str, "pb\n", 3))
		pb(a, b, size, 0);
	else if (!ft_strncmp(cmd_str, "sa\n", 3))
		sa(a, size, 0);
	else if (!ft_strncmp(cmd_str, "sb\n", 3))
		sb(b, size, 0);
	else if (!ft_strncmp(cmd_str, "ss\n", 3))
		ss(a, b, size, 0);
	else
		if (act_cmd_r_rr(a, b, size, cmd_str) == -1)
			return (-1);
	return (0);
}

int	get_cmd(t_stack *a, t_stack *b, int size)
{
	int		cnt;
	char	*cmd_str;

	cnt = 0;
	cmd_str = get_next_line(0);
	while (cmd_str)
	{
		if (act_cmd_p_s(a, b, size, cmd_str) == -1)
		{
			free(cmd_str);
			return (-1);
		}
		free(cmd_str);
		cmd_str = get_next_line(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (argc == 1)
		return (free_n_print_out(0, 1, 0, 0));
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		return (free_n_print_out(0, 1, 0, 0));
	if (!b)
		return (free_n_print_out(2, 1, a, 0));
	if (init_stack(a, b, argv) <= 0)
		return (free_n_print_out(1, 1, a, b));
	size = a->in;
	if (a->in == 1 || !check_sort_a(a, size))
		return (0);
	if (get_cmd(a, b, a->in) == -1)
		return (free_n_print_out(1, 1, a, b));
	if (!check_sort_a(a, size) && !(b->in - b->out))
		ft_putstr_fd("OK\n", 1);
	else if (check_sort_a(a, size) || b->in - b->out)
		ft_putstr_fd("KO\n", 1);
	free_n_print_out(1, 0, a->arr, b->arr);
	return (free_n_print_out(1, 0, a, b));
}

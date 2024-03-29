/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:29 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/16 12:45:51 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1 || !argv[1][0])
		return (0);
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!a || !b)
		return (free_n_print_out(1, 1, a, b));
	if (init_stack(a, b, argv) == -1)
		return (free_n_print_out(1, 1, a, b));
	if (a->size == 1 || !check_sort_a(a))
	{
		free_n_print_out(1, 0, a->arr, b->arr);
		return (free_n_print_out(1, 0, a, b));
	}
	if (solve(a, b) == -1)
	{
		free_n_print_out(1, 0, a->arr, b->arr);
		return (free_n_print_out(1, 1, a, b));
	}
	free_n_print_out(1, 0, a->arr, b->arr);
	return (free_n_print_out(1, 0, a, b));
}

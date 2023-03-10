/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:29 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/09 16:27:36 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	if (argc == 1)
		return (free_n_print_out(0, 1, 0, 0));
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		return (free_n_print_out(0, 1, 0, 0));
	if (!b)
		return (free_n_print_out(2, 1, a, 0));
	if (init_stack(a, b, argv) == -1)
		return (free_n_print_out(1, 1, a, b));
	if (a->in <= 1 || !check_sort_a(a, a->in))
		return (0);
	if (sorting(a, b, a->in) == -1)
	{
		free_n_print_out(1, 0, a->arr, b->arr);
		return (free_n_print_out(1, 1, a, b));
	}
	free_n_print_out(1, 0, a->arr, b->arr);
	return (free_n_print_out(1, 0, a, b));
}

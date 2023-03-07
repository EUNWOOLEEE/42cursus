/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:29 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/07 16:53:22 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//front가 top
//ARG=$(jot -r 10 1 500 | sort -uR | tr '\n' ' ' | rev | sed 's/ //' | rev); ./push_swap $ARG | ./checker $ARG
void	asd (void)
{
	system ("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	atexit (asd);
	(void)argc;
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!a || !b)
		return (free_n_print_out(5, 0, 0));
	if (init_stack(a, b, argv) == -1)
		return (free_n_print_out(1, a, b));
	if (a->in <= 1 || !check_sort_a(a, a->in)) //인자가 1개 이하거나, 이미 정렬된 상태면
		return (0);
	if (sorting(a, b, a->in) == -1)
	{
		free_n_print_out(4, a->arr, b->arr);
		return (free_n_print_out(1, a, b)); //다 free하고 종료
	}
	free_n_print_out(4, a->arr, b->arr);
	return (free_n_print_out(4, a, b)); //다 free하고 종료
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:29 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/21 00:08:52 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int *a;
	int *b;
	int *a_idx;
	int *b_idx;

	a_idx = (int *)ft_calloc(2, sizeof(int)); //[0]=front, [1]=rear
	b_idx = (int *)ft_calloc(2, sizeof(int));
	if (!a_idx || !b_idx)
		return (error_out());
	a_idx[1] = init_stack(&a, &b, argv);
	if(a_idx[1] == -1)
		return (error_out());
	sorting(a, b, a_idx, b_idx);
}
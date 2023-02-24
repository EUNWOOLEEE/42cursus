/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:29 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/24 14:44:38 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//front가 top

int main(int argc, char **argv)
{
	t_struct *a;
	t_struct *b;

	(void)argc;
	a = (t_struct *)malloc(sizeof(t_struct) * 1);
	b = (t_struct *)malloc(sizeof(t_struct) * 1);
	if(!a || !b)
		return (error_out());
	if(init_stack(a, b, argv) == -1)
		return (error_out());
	sorting(a, b, a->in);
}
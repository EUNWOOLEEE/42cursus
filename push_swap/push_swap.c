/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:29 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/21 19:55:48 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//front가 top

int main(int argc, char **argv)
{
	t_struct *a;
	t_struct *b;

	a = (t_struct *)malloc(sizeof(t_struct) * 1);
	b = (t_struct *)malloc(sizeof(t_struct) * 1);
	if(!a || !b)
		return (error_out());
	a->rear = init_stack(a, b, argv);
	if(a->rear == -1)
		return (error_out());
	sorting(a, b);
}
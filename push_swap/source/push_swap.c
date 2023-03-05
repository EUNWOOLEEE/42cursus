/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:29 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/06 02:06:27 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//front가 top
//free, 널가드, 파싱 예외처리 등등 해야됨

int main(int argc, char **argv)
{
	t_struct *a;
	t_struct *b;

	(void)argc;
	a = (t_struct *)malloc(sizeof(t_struct));
	b = (t_struct *)malloc(sizeof(t_struct));
	if(!a || !b)
		return (error_out());
	if(init_stack(a, b, argv) == -1)
		return (error_out());
	sorting(a, b, a->in);
}
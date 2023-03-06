/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:29 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/06 18:58:03 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//front가 top
//종료 시와 에러 시 free, 널가드, 파싱 예외처리 등등 해야됨
//jot -r 100 1 500 | sort -uR | xargs ./push_swap

int main(int argc, char **argv)
{
	t_struct *a;
	t_struct *b;

	(void)argc;
	a = (t_struct *)malloc(sizeof(t_struct));
	b = (t_struct *)malloc(sizeof(t_struct));
	if (!a || !b)
		return (free_n_print_out(4, 0, 0));
	if (init_stack(a, b, argv) == -1)
		return (free_n_print_out(1, a, b));
	if (a->in <= 1 || !check_sort_a(a, a->in)) //인자가 1개 이하거나, 이미 정렬된 상태면
		return (0);
	if (sorting(a, b, a->in) == -1)
		return (0); //다 free하고 종료
	return (0); //다 free하고 종료
}
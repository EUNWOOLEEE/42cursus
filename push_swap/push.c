/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:09 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/20 23:38:08 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//비어있을 경우(옮길 원소가 없을 경우)에는 아무 동작도 하지 않음

void pa(int *a, int *b, int *a_idx, int *b_idx, int size) //b의 top에 위치한 원소 한 개를 a의 top으로 옮김
{
	if(!count_num(b_idx[0], b_idx[1]))
		return ;

	a_idx[0] = (a_idx[0] - 1) % size;
	a[a_idx[0]] = b[b_idx[0]];
	b_idx[0] = (b_idx[0] + 1) % size;
}

void pb(int *a, int *b, int *a_idx, int *b_idx, int size) //a의 top에 위치한 원소 한 개를 b의 top으로 옮김
{
	if(!count_num(a_idx[0], a_idx[1]))
		return ;

	b_idx[0] = (b_idx[0] - 1) % size;
	b[b_idx[0]] = a[a_idx[0]];
	a_idx[0] = (a_idx[0] + 1) % size;
}
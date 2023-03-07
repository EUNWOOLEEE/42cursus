/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:13:37 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/06 22:38:11 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//삭제하기!!!!!!!!!!!
void test_print(t_stack *a, t_stack *b, int size)
{
	printf("a f: %d r: %d\n", a->front, a->rear);
	printf("b f: %d r: %d\n", b->front, b->rear);
	for(int cnt = size, i = a->front, j = b->front; cnt; cnt--, i++, j++)
		printf("[%d]%d  [%d]%d\n", i % size, a->arr[i % size], j % size, b->arr[j % size]);
	printf("\n");
}

int abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

// 1-both_free, print(0) / 2-first_free(0) / 3-both_free(-1) / 4-both_free(0) / 5-print(-1)
int free_n_print_out(int flag, void *a, void *b)
{
	if (flag == 1 || flag == 3 || flag == 4)
	{
		free(a);
		free(b);
	}
	if (flag == 2)
		free(a);
	if (flag == 1 || flag == 5)
		ft_putstr_fd("Error\n", 1);
	if (flag == 3 || flag == 5)
		return (-1);
	return (0);
}

int check_sort_a(t_stack *a, int size) //a가 오름차순으로 정렬 돼있는지 확인
{
	int front;
	int num;
	int pre;

	front = a->front;
	num = size;
	pre = a->arr[front++ % size];
	while (--num)
	{
		if(pre > a->arr[front % size])
			return (-1);
		pre = a->arr[front++ % size];
	}
	return (0);
}

int check_sort_b(t_stack *b, int size) //b가 내림차순으로 정렬 돼있는지 확인
{
	int front;
	int num;
	int pre;

	front = b->front;
	num = b->in - b->out;
	pre = b->arr[front++ % size];
	if (!num) // b가 비어있을 때
		return (0);
	while (--num)
	{
		if(pre < b->arr[front % size])
			return (-1);
		pre = b->arr[front++ % size];
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:59:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/01 20:44:11 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test_print(t_struct *a, t_struct *b, int size)
{
	printf("a f: %d r: %d\n", a->front, a->rear);
	printf("b f: %d r: %d\n", b->front, b->rear);
	for(int cnt = size, i = a->front, j = b->front; cnt; cnt--)
		printf("%d  %d\n", a->arr[i++ % size], b->arr[j++ % size]);
	printf("\n");
}

void move_to_b(t_struct *a, t_struct *b, int size)
{
	int i;
	int first;
	int second;
	int last;

	i = 0;
	while (i < size)
	{
		first = a->arr[a->front];
		second = a->arr[(a->front + 1) % size];
		last = a->arr[a->rear];

		if(last < first && last < second)
			rra(a, size);
		else if(second < first)
			sa(a, size);

		pb(a, b, size);

		first = b->arr[b->front];
		second = b->arr[(b->front + 1) % size];
		last = b->arr[b->rear];

		if(last > first && last > second)
			rrb(b, size);
		else if(second > first)
			sb(b, size);

		i++;
	}
}

int find_max_in_b(t_struct *b, int size)
{
	int max_idx;
	int max;
	int cur;
	int cnt;
	int idx;

	max = 0;
	cnt = b->in - b->out;
	idx = b->front;

	while (cnt--)
	{
		cur = b->arr[idx % size];
		if (max < cur)
		{
			max = cur;
			max_idx = idx % size;
		}
		idx++;
	}
	return max_idx;
}

int get_optimum_idx(t_struct *a, int size, int num)
{
	int idx;
	int res;
	int cnt;

	idx = a->front;
	res = a->front;
	cnt = a->in - a->out;

	while (cnt--)
	{
		if (a->arr[idx] < num && num < a->arr[(idx + 1) % size])
			res = idx % size;
		idx = (idx + 1) % size;
	}
	return res;
}

void go_to_a(t_struct *a, t_struct *b, int size, int *cmd)
{
	// b에서 제일 큰 수를 찾아서 넘기니까 ra,rra 쓸 일이 없음. 활용방법 생각해보기
	// while (cmd[0] && cmd[2])
	// {
	// 	rr(a, b, size);
	// 	cmd[0]--;
	// 	cmd[2]--;
	// }

	// while (cmd[1] && cmd[3])
	// {
	// 	rrr(a, b, size);
	// 	cmd[1]--;
	// 	cmd[3]--;
	// }

	while (cmd[0]--)
		ra(a, size);
	while (cmd[1]--)
		rra(a, size);
	while (cmd[2]--)
		rb(b, size);
	while (cmd[3]--)
		rrb(b, size);
	pa(a, b, size);
}

void get_cmd_cnt(t_struct *a, t_struct *b, int size, int idx_a, int idx_b)
{
	int cmd[4];

	ft_memset(cmd, 0, sizeof(int) * 4); //0-ra, 1-rra, 2-rb, 3-rrb

	if (abs(idx_a - a->front) <= abs(idx_a - a->rear))
		cmd[0] = abs(idx_a - a->front);
	else
		cmd[1] = abs(idx_a - a->rear) + 1;

	if (abs(idx_b - b->front) <= abs(idx_b - b->rear))
		cmd[2] = abs(idx_b - b->front);
	else
		cmd[3] = abs(idx_b - b->rear) + 1;

	go_to_a(a, b, size, cmd);
}

void sorting(t_struct *a, t_struct *b, int size)
{
	// test_print(a, b, size);

	int cnt;
	int max_idx;
	int opt_idx;

	cnt = 2;
	if(size <= 3)
		while (cnt--)
			conquer_small(a, b, size);
	else if(size <= 5)
		while (check_sort_a(a, size))
		{
			cnt = 2;
			devide_small(a, b, size);
			while (cnt--)
				conquer_small(a, b, size);
			combine_small(a, b, size);
		}
	else
	{
		move_to_b(a, b, size);
		// test_print(a, b, size);
		cnt = size;
		while (cnt--)
		{
			max_idx = find_max_in_b(b, size);
			opt_idx = get_optimum_idx(a, size, b->arr[max_idx]);
			get_cmd_cnt(a, b, size, opt_idx, max_idx);
			// test_print(a, b, size);
		}
	}
	// test_print(a, b, size);
}
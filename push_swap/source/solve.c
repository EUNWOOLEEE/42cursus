/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:59:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/06 02:46:45 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test_print(t_struct *a, t_struct *b, int size)
{
	printf("a f: %d r: %d\n", a->front, a->rear);
	printf("b f: %d r: %d\n", b->front, b->rear);
	for(int cnt = size, i = a->front, j = b->front; cnt; cnt--, i++, j++)
		printf("[%d]%d  [%d]%d\n", i % size, a->arr[i % size], j % size, b->arr[j % size]);
	printf("\n");
}

t_num *get_min_and_fivot_num(t_struct *a, int size)
{
	int *arr;
	int i;
	int j;
	int tmp;
	t_num *nums;

	arr = (int *)malloc(sizeof(int) * size);
	ft_memmove(arr, a->arr, sizeof(int) * size);
	nums = (t_num *)ft_calloc(1, sizeof(t_num));
	
	nums->min = 2147483647;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		if (nums->min > arr[i])
			nums->min = arr[i];
		i++;
	}
	nums->one_third = arr[size / 3 - 1];
	nums->two_third = arr[size / 3 * 2 - 1];
	return nums;
}

int move_to_b(t_struct *a, t_struct *b, int size)
{
	int cnt;
	t_num *nums;

	cnt = size;
	nums = get_min_and_fivot_num(a, size);

	while (cnt--)
	{
		if (nums->min > a->arr[a->front])
			nums->min = a->arr[a->front];
		if (a->arr[a->front] <= nums->two_third)
			pb(a, b, size);
		if (a->arr[a->front] <= nums->one_third)
			rb(b, size);
		else
			ra(a, size);
	}
	cnt = a->in - a->out;
	while (cnt--)
		pb(a, b, size);
	return nums->min;
}

//이 함수 조건이 이상한 것 같음. 다시 생각해보기
void get_opt_idx_in_a(t_struct *a, t_struct *b, int size, t_cmd *tmp)
{
	int idx;
	int cnt;
	int num;
	int min;
	int min_idx;

	if (!(a->in - a->out))
	{
		tmp->idx_a = a->front;
		return ;
	}

	idx = a->front;
	cnt = a->in - a->out;
	num = b->arr[tmp->idx_b];
	min = 2147483647;

	while (cnt--)
	{
		if (a->arr[idx] < min)
		{
			min = a->arr[idx];
			min_idx = idx;
		}
		idx = (idx + 1) % size;
	}
	if (min > num)
	{
		if (a->arr[a->front] < a->arr[a->rear])
			tmp->idx_a = a->front;
		else
			tmp->idx_a = min_idx;
		return ;
	}

	//num보다 작은 것중에 제일 큰 수 찾기
	idx = a->front;
	cnt = a->in - a->out;
	num = b->arr[tmp->idx_b];
	min = -2147483648;
	while (cnt--)
	{
		if (min < a->arr[idx] && a->arr[idx] < num)
		{
			min = a->arr[idx];
			min_idx = idx;
		}
		idx = (idx + 1) % size;
	}
	if (min_idx == a->rear)
		tmp->idx_a = a->front;
	else
		tmp->idx_a = (min_idx + 1) % size;
}

int get_cmd_cnt(t_struct *a, t_struct *b, t_cmd *cmd)
{
	if (abs(cmd->idx_a - a->front) <= abs(cmd->idx_a - a->rear))
		cmd->ra = abs(cmd->idx_a - a->front);
	else
		cmd->rra = abs(cmd->idx_a - a->rear) + 1;

	if (abs(cmd->idx_b - b->front) <= abs(cmd->idx_b - b->rear))
		cmd->rb = abs(cmd->idx_b - b->front);
	else
		cmd->rrb = abs(cmd->idx_b - b->rear) + 1;
	return (abs(cmd->ra - cmd->rb) + abs(cmd->rra - cmd->rrb));
}

void find_opt_num_in_b(t_struct *a, t_struct *b, int size, t_cmd *cmd)
{
	int min;
	int cur;
	int cnt;
	int idx;
	t_cmd *tmp;

	min = 2147483647;
	cnt = b->in - b->out;
	idx = b->front;
	tmp = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	
	while (cnt--)
	{
		memset(tmp, 0, sizeof(t_cmd));
		tmp->idx_b = idx;
		get_opt_idx_in_a(a, b, size, tmp);
		cur = get_cmd_cnt(a, b, tmp);
		if(cur < min)
		{
			min = cur;
			ft_memmove(cmd, tmp, sizeof(t_cmd));
		}
		idx = (idx + 1) % size;
	}
	free(tmp);
}

void go_to_a(t_struct *a, t_struct *b, int size, t_cmd *cmd)
{
	while (cmd->ra && cmd->rb)
	{
		rr(a, b, size);
		cmd->ra--;
		cmd->rb--;
	}

	while (cmd->rra && cmd->rrb)
	{
		rrr(a, b, size);
		cmd->rra--;
		cmd->rrb--;
	}

	while (cmd->ra--)
		ra(a, size);
	while (cmd->rra--)
		rra(a, size);
	while (cmd->rb--)
		rb(b, size);
	while (cmd->rrb--)
		rrb(b, size);
	pa(a, b, size);
}

int get_min_idx(t_struct *a, int size, int min)
{
	int idx;
	int cnt;
	
	cnt = size;
	idx = a->front;
	while (cnt--)
	{
		if (a->arr[idx] == min)
			return idx;
		idx = (idx + 1) % size;
	}
	return idx;
}

void sorting(t_struct *a, t_struct *b, int size)
{
	// test_print(a, b, size);

	int cnt;
	int min;
	int min_idx;
	t_cmd *cmd;

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
		min = move_to_b(a, b, size);
		// test_print(a, b, size);

		cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
		cnt = size;
		while (cnt--)
		{
			find_opt_num_in_b(a, b, size, cmd);
			go_to_a(a, b, size, cmd);
			// test_print(a, b, size);
		}
		min_idx = get_min_idx(a, size, min);
		if (abs(min_idx - a->front) <= abs(min_idx - a->rear))
			while (a->arr[a->front] != min)
				ra(a, size);
		else
			while (a->arr[a->front] != min)
				rra(a, size);
	}
	// test_print(a, b, size);
}
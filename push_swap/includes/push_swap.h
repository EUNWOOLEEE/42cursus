/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:10 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/09 01:46:20 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../Libft/includes/libft.h"

typedef struct s_stack
{
	int	*arr;
	int	front;
	int	rear;
	int	in;
	int	out;
	int	min;
	int	min_idx;
}t_stack;

typedef struct s_fivot
{
	int	one_third;
	int	two_third;
}t_fivot;

typedef struct s_cmd
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	idx_a;
	int	idx_b;
}t_cmd;

typedef struct s_mc
{
	int cnt;
	int max_in_min_cnt;
	int	min_cnt;
	int	cur_cnt;
	int	cur_idx;
}t_mc;

//다른 파일에서 쓰이지 않는 함수들 static으로 만들기
//utils
int		abs(int num);
int		free_n_print_out(int flag, int print, void *a, void *b);
int		check_sort_a(t_stack *a, int size);
int		check_sort_b(t_stack *b, int size);

//init
int		init_stack(t_stack *a, t_stack *b, char **argv);
int		check_valid(char **argv);
int		check_overlap(int *a, int cnt, int num);
int		parsing(t_stack *a, char **argv);

//solve
void	get_min_num(t_stack *a, int size);
int		greedy(t_stack *a, t_stack *b, t_cmd *cmd, int size);
int		sorting(t_stack *a, t_stack *b, int size);

//under_five
void	under_five(t_stack *a, t_stack *b, int size);
void	devide_small(t_stack *a, t_stack *b, int size);
void	conquer_small(t_stack *a, t_stack *b, int size);
void	combine_small(t_stack *a, t_stack *b, int size);

//a_to_b
void	sort_arr(int *arr, int size);
t_fivot	*get_min_and_fivot_num(t_stack *a, int size);
int		move_to_b(t_stack *a, t_stack *b, int size);

//b_to_a
void	get_opt_idx_in_a(t_stack *a, t_stack *b, int size, t_cmd *tmp);
void	max_in_less_than_num(t_stack *a, t_stack *b, int size, t_cmd *tmp);
int		get_cmd_cnt(t_stack *a, t_stack *b, t_cmd *cmd);
int		find_opt_num_in_b(t_stack *a, t_stack *b, int size, t_cmd *cmd);
void	go_to_a(t_stack *a, t_stack *b, int size, t_cmd *cmd);

//cmd
void	sa(t_stack *a, int size);
void	sb(t_stack *b, int size);
void	ss(t_stack *a, t_stack *b, int size);
void	pa(t_stack *a, t_stack *b, int size);
void	pb(t_stack *a, t_stack *b, int size);
void	ra(t_stack *a, int size);
void	rb(t_stack *b, int size);
void	rr(t_stack *a, t_stack *b, int size);
void	rra(t_stack *a, int size);
void	rrb(t_stack *b, int size);
void	rrr(t_stack *a, t_stack *b, int size);

#endif
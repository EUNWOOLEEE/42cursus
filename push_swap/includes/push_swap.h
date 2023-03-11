/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:10 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/11 19:00:41 by eunwolee         ###   ########.fr       */
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
void	print_cmd(t_list *head);

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
void	devide(t_stack *a, t_stack *b, int size);
void	conquer(t_stack *a, t_stack *b, int size);
void	combine(t_stack *a, t_stack *b, int size);

//a_to_b
void	sort_arr(int *arr, int size);
t_fivot	*get_fivot_num(t_stack *a, int size);
int		move_to_b(t_stack *a, t_stack *b, int size, t_fivot *fivot);

//b_to_a
void	get_opt_idx_in_a(t_stack *a, t_stack *b, int size, t_cmd *tmp);
void	max_in_less_than_num(t_stack *a, t_stack *b, int size, t_cmd *tmp);
int		get_cmd_cnt(t_stack *a, t_stack *b, int size, t_cmd *cmd);
void	go_to_a(t_stack *a, t_stack *b, int size, t_cmd *cmd, t_list **head);
int		find_more_than_fivot(t_stack *b, int size, int fivot);

int		find_opt_num_in_b_by_greedy(t_stack *a, t_stack *b, int size, t_cmd *cmd);
int		find_opt_num_in_b_by_fivot(t_stack *a, t_stack *b, int size, t_cmd *cmd, t_fivot *fivot);

//cmd
char	*sa(t_stack *a, int size, int print);
char	*sb(t_stack *b, int size, int print);
char	*ss(t_stack *a, t_stack *b, int size, int print);
char	*pa(t_stack *a, t_stack *b, int size, int print);
char	*pb(t_stack *a, t_stack *b, int size, int print);
char	*ra(t_stack *a, int size, int print);
char	*rb(t_stack *b, int size, int print);
char	*rr(t_stack *a, t_stack *b, int size, int print);
char	*rra(t_stack *a, int size, int print);
char	*rrb(t_stack *b, int size, int print);
char	*rrr(t_stack *a, t_stack *b, int size, int print);

#endif
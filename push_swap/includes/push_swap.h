/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:10 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/12 18:50:43 by eunwolee         ###   ########.fr       */
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
	int size;
	int	min;
	int	min_idx;
}t_stack;

typedef struct s_pivot
{
	int	one_third;
	int	two_third;
}t_pivot;

typedef struct s_cmd
{
	int sa;
	int sb;
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

/*push_swap*/
// main

/*init*/
int		init_stack(t_stack *a, t_stack *b, char **argv);
// static int		check_valid(char **argv);
// static int		check_overlap(int *a, int cnt, int num);
// static int		parsing(t_stack *a, char **argv);

/*solve*/
int		solve(t_stack *a, t_stack *b);
// static int		sorting(t_stack *a, t_stack *b, t_cmd *cmd, t_pivot *pivot);
// static t_stack *make_tmp_stack(t_stack *src);
// static t_list	*solve_greedy(t_stack *a, t_stack *b, t_cmd *cmd);
// static t_list	*solve_pivot(t_stack *a, t_stack *b, t_cmd *cmd, t_pivot *pivot);

/*under_five*/
void		under_five(t_stack *a, t_stack *b, t_cmd *cmd);
// static int	check_first_second(t_stack *a);
// static void	devide(t_stack *a, t_stack *b);
// static void	conquer(t_stack *a, t_stack *b, t_cmd *cmd);
// static void	act_cmd(t_stack *a, t_stack *b, t_cmd *cmd);

/*ready*/
t_pivot	*get_pivots(t_stack *a);
int		move_to_b(t_stack *a, t_stack *b, t_pivot *pivot);
void	get_min_num(t_stack *a);
// static void	sort_arr(int *arr, int size);

/*go_to_a*/
void	go_to_a(t_stack *a, t_stack *b, t_cmd *cmd, t_list **head);
void	get_opt_idx_in_a(t_stack *a, t_stack *b, t_cmd *tmp);
int		get_cmd_cnt(t_stack *a, t_stack *b, t_cmd *cmd);
int		find_more_than_pivot(t_stack *b, int pivot);
// void	max_in_less_than_num(t_stack *a, t_stack *b, t_cmd *tmp);

/*find_best*/
int	find_opt_num_in_b_by_pivot(t_stack *a, t_stack *b, t_cmd *cmd, t_pivot *pivot);
int	find_opt_num_in_b_by_greedy(t_stack *a, t_stack *b, t_cmd *cmd);
// static int set_pivot(t_stack *b, t_pivot *pivot);
// static t_mc *set_min_n_cur(t_stack *b);
// static void set_mc_n_cmd(t_stack *b, t_cmd *cmd, t_cmd *tmp, t_mc *mc);

/*utils*/
int		abs(int num);
void	print_cmd(t_list *head);
int		free_n_print_out(int flag, int print, void *a, void *b);
int		check_sort_a(t_stack *a);
int		check_sort_b(t_stack *b);

/*cmd*/
char	*sa(t_stack *a, int print);
char	*sb(t_stack *b, int print);
char	*ss(t_stack *a, t_stack *b, int print);
char	*pa(t_stack *a, t_stack *b, int print);
char	*pb(t_stack *a, t_stack *b, int print);
char	*ra(t_stack *a, int print);
char	*rb(t_stack *b, int print);
char	*rr(t_stack *a, t_stack *b, int print);
char	*rra(t_stack *a, int print);
char	*rrb(t_stack *b, int print);
char	*rrr(t_stack *a, t_stack *b, int print);
int		set_idx(int idx, int size);

/*checker*/
// main
// static int	get_cmd(t_stack *a, t_stack *b);
// static int	act_cmd_p_s(t_stack *a, t_stack *b, char *cmd_str);
// static int	act_cmd_r_rr(t_stack *a, t_stack *b, char *cmd_str);

#endif
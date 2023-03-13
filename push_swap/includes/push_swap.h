/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:10 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/13 14:12:34 by eunwolee         ###   ########.fr       */
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
	int	size;
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
	int	sa;
	int	sb;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	idx_a;
	int	idx_b;
}t_cmd;

typedef struct s_mc
{
	int	cnt;
	int	min_cnt;
	int	cur_cnt;
	int	cur_idx;
	int	max_in_min_cnt;
}t_mc;

int		init_stack(t_stack *a, t_stack *b, char **argv);
int		solve(t_stack *a, t_stack *b);
void	under_five(t_stack *a, t_stack *b, t_cmd *cmd);
t_pivot	*get_pivots(t_stack *a);
int		move_to_b(t_stack *a, t_stack *b, t_pivot *pivot);
void	get_min_num(t_stack *a);
void	go_to_a(t_stack *a, t_stack *b, t_cmd *cmd, t_list **head);
void	get_opt_idx_in_a(t_stack *a, t_stack *b, t_cmd *tmp);
int		get_cmd_cnt(t_stack *a, t_stack *b, t_cmd *cmd);
int		find_more_than_pivot(t_stack *b, int pivot);
int		find_opt_num_in_b_p(t_stack *a, t_stack *b, t_cmd *cmd, t_pivot *pivot);
int		find_opt_num_in_b_g(t_stack *a, t_stack *b, t_cmd *cmd);
int		abs(int num);
void	print_cmd(t_list *head);
int		free_n_print_out(int flag, int print, void *a, void *b);
int		check_sort_a(t_stack *a);
int		check_sort_b(t_stack *b);
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

#endif
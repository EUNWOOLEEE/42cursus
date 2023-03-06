/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:10 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/06 19:27:54 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdio.h> //지우기!!!

# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"

typedef struct s_struct
{
	int *arr;
	int front;
	int rear;
	int in;
	int out;
	int min;
	int min_idx;
} t_struct;

typedef struct s_num
{
	int one_third;
	int two_third;
} t_num;

typedef struct s_cmd
{
	int ra;
	int rb;
	int rra;
	int rrb;
	int idx_a;
	int idx_b;
} t_cmd;

//삭제하기!!!!!!!!!!!!!!!!!!
void test_print(t_struct *a, t_struct *b, int size);

//다른 파일에서 쓰이지 않는 함수들 static으로 만들기
//utils
int abs(int num);
int free_n_print_out(int flag, void *a, void *b);
int check_sort_a(t_struct *a, int size);
int check_sort_b(t_struct *b, int size);

//init
int init_stack(t_struct *a, t_struct *b, char **argv);
int check_valid(char **argv);
int check_overlap(int *a, int cnt, int num);
int parsing(t_struct *a, char **argv);

//solve
void get_min_num(t_struct *a, int size);
int greedy(t_struct *a, t_struct *b, t_cmd *cmd, int size);
int sorting(t_struct *a, t_struct *b, int size);

//under_five
void under_five(t_struct *a, t_struct *b, int size);
void devide_small(t_struct *a, t_struct *b, int size);
void conquer_small(t_struct *a, t_struct *b, int size);
void combine_small(t_struct *a, t_struct *b, int size);

//a_to_b
void sort_arr(int *arr, int size);
t_num *get_min_and_fivot_num(t_struct *a, int size);
int move_to_b(t_struct *a, t_struct *b, int size);

//b_to_a
void get_opt_idx_in_a(t_struct *a, t_struct *b, int size, t_cmd *tmp);
void max_in_less_than_num(t_struct *a, t_struct *b, int size, t_cmd *tmp);
int get_cmd_cnt(t_struct *a, t_struct *b, t_cmd *cmd);
int find_opt_num_in_b(t_struct *a, t_struct *b, int size, t_cmd *cmd);
void go_to_a(t_struct *a, t_struct *b, int size, t_cmd *cmd);

//cmd
void sa(t_struct *a, int size);
void sb(t_struct *b, int size);
void ss(t_struct *a, t_struct *b, int size);
void pa(t_struct *a, t_struct *b, int size);
void pb(t_struct *a, t_struct *b, int size);
void ra(t_struct *a, int size);
void rb(t_struct *b, int size);
void rr(t_struct *a, t_struct *b, int size);
void rra(t_struct *a, int size);
void rrb(t_struct *b, int size);
void rrr(t_struct *a, t_struct *b, int size);

#endif
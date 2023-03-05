/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:10 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/06 02:53:00 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdio.h> //지우기!!!

# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"

//현재 스택의 min값이랑 해당 주소를 계속 구하지 말고 구조체에 넣어서 업데이트하게 할까?
typedef struct s_struct
{
	int *arr;
	int front;
	int rear;
	int in;
	int out;
} t_struct;

typedef struct s_num
{
	int min;
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

int count_num(int in, int out);
int abs(int num);
int check_sort_a(t_struct *a, int size);
int check_sort_b(t_struct *b, int size);
int error_out(); //free 넣어야됨
int check_valid(char **argv);
int check_overlap(t_struct *a, int size);
int init_stack(t_struct *a, t_struct *b, char **argv);
void parsing(t_struct *a, char **argv);
void sorting(t_struct *a, t_struct *b, int size);

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

//case_under_five
void devide_small(t_struct *a, t_struct *b, int size);
void conquer_small(t_struct *a, t_struct *b, int size);
void combine_small(t_struct *a, t_struct *b, int size);

#endif
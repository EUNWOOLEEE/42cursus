/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:10 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/24 00:01:33 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //지우기!!!

# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"

typedef struct s_struct
{
	int *arr;
	int front;
	int rear;
	int in;
	int out;
} t_struct;

int count_num(int in, int out);
int check_sort_a(t_struct *a, int size);
int check_sort_b(t_struct *b, int size);
int error_out(); //free 넣어야됨
int check_valid(char **argv);
int init_stack(t_struct *a, t_struct *b, char **argv);
void parsing(t_struct *a, char **argv);
void sorting(t_struct *a, t_struct *b, int size);
void sa(t_struct *a, t_struct *b, int size);
void sb(t_struct *a, t_struct *b, int size);
void ss(t_struct *a, t_struct *b, int size);
void pa(t_struct *a, t_struct *b, int size);
void pb(t_struct *a, t_struct *b, int size);
void ra(t_struct *a, t_struct *b, int size);
void rb(t_struct *a, t_struct *b, int size);
void rr(t_struct *a, t_struct *b, int size);
void rra(t_struct *a, t_struct *b, int size);
void rrb(t_struct *a, t_struct *b, int size);
void rrr(t_struct *a, t_struct *b, int size);

#endif
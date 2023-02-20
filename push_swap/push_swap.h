/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:10 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/21 00:05:19 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //지우기!!!

# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"

int count_num(int front, int rear);
int check_sort(int *a, int *a_idx, int size);
int error_out(); //free 넣어야됨
int check_valid(char **argv);
int init_stack(int **a, int **b, char **argv);
void parsing(int *a, char **argv);
void sorting(int *a, int *b, int *a_idx, int *b_idx);
void sa(int *a, int *b, int *a_idx, int *b_idx, int size);
void sb(int *a, int *b, int *a_idx, int *b_idx, int size);
void ss(int *a, int *b, int *a_idx, int *b_idx, int size);
void pa(int *a, int *b, int *a_idx, int *b_idx, int size);
void pb(int *a, int *b, int *a_idx, int *b_idx, int size);
void ra(int *a, int *b, int *a_idx, int *b_idx, int size);
void rb(int *a, int *b, int *a_idx, int *b_idx, int size);
void rr(int *a, int *b, int *a_idx, int *b_idx, int size);
void rra(int *a, int *b, int *a_idx, int *b_idx, int size);
void rrb(int *a, int *b, int *a_idx, int *b_idx, int size);
void rrr(int *a, int *b, int *a_idx, int *b_idx, int size);

#endif
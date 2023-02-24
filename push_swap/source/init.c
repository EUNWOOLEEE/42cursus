/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:59:09 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/24 14:44:52 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int init_stack(t_struct *a, t_struct *b, char **argv)
{
	int size;

	size = check_valid(argv);
	if(size <= 0)
		return (-1);
	a->arr = (int *)ft_calloc(size, sizeof(int));
	b->arr = (int *)ft_calloc(size, sizeof(int));
	if(!a->arr || !b->arr)
		return (-1);
	parsing(a, argv);
	a->rear = size - 1;
	a->in = size;
	return (size);
}

int check_valid(char **argv)
{
	int num;
	int i;
	int j;

	num = 0;
	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{ 
			if(ft_isdigit(argv[i][j + 1]) && (argv[i][j] == '+' || argv[i][j] == '-')) //부호 다음 공백 있는 경우 때문에 다음 자리 체크
				j++;
			if(ft_isdigit(argv[i][j]))
			{
				while(ft_isdigit(argv[i][j]))
					j++;
				num++;
			}
			if(argv[i][j] == ' ')
				j++;
			else if(argv[i][j] != '\0')
				return (-1);
		}
		i++;
	}
	return num;
}

void parsing(t_struct *a, char **argv)
{
	int idx;
	int sign;
	int i;
	int j;

	idx = 0;
	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			sign = 1;
			if(argv[i][j] == '+' || argv[i][j] == '-')
			{
				if(argv[i][j] == '-')
					sign = -1;
				j++;
			}
			while(ft_isdigit(argv[i][j])) //공백도 아니고 널도 아니어야 함
				a->arr[idx] = a->arr[idx] * 10 + (argv[i][j++] - '0');
			a->arr[idx++] *= sign;
			if(argv[i][j] == ' ')
				j++;
		}
		i++;
	}
}
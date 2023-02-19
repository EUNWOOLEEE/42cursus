/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:09:29 by eunwolee          #+#    #+#             */
/*   Updated: 2023/02/20 02:23:10 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int check_valid(char **argv);
int init_stack(int **a, int **b, char **argv);
void parsing(int *a, char **argv);
int error_out(); //free 넣어야함

int main(int argc, char **argv)
{
	int *a;
	int *b;
	int bottom;

	bottom = init_stack(&a, &b, argv);
	if(bottom == -1)
		return (error_out());
}

int init_stack(int **a, int **b, char **argv)
{
	int size;
	
	size = check_valid(argv);
	if(size <= 0)
		return (error_out());
	*a = (int *)ft_calloc(size, sizeof(int));
	*b = (int *)ft_calloc(size, sizeof(int));
	if(!*a || !*b)
		return (-1);
	parsing(*a, argv);
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

void parsing(int *a, char **argv)
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
				a[idx] = a[idx] * 10 + (argv[i][j++] - '0');
			a[idx++] *= sign;
			if(argv[i][j] == ' ')
				j++;
		}
		i++;
	}
}

int error_out()
{
	ft_putstr_fd("error!\n", 1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/12 16:35:43 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*sa(t_stack *a, int print)
{
	int	tmp;

	if (a->in - a->out <= 1)
		return (0);
	tmp = a->arr[a->front];
	a->arr[a->front] = a->arr[(a->front + 1) % a->size];
	a->arr[(a->front + 1) % a->size] = tmp;
	if (print)
	{
		write(1, "sa\n", 3);
		return (0);
	}
	return (ft_strdup("sa"));
}

char	*sb(t_stack *b, int print)
{
	int	tmp;

	if (b->in - b->out <= 1)
		return (0);
	tmp = b->arr[b->front];
	b->arr[b->front] = b->arr[(b->front + 1) % b->size];
	b->arr[(b->front + 1) % b->size] = tmp;
	if (print)
	{
		write(1, "sb\n", 3);
		return (0);
	}
	return (ft_strdup("sb"));
}

char	*ss(t_stack *a, t_stack *b, int print)
{
	int	tmp;

	if (a->in - a->out <= 1)
		return (0);
	if (b->in - b->out <= 1)
		return (0);
	tmp = a->arr[a->front];
	a->arr[a->front] = a->arr[(a->front + 1) % a->size];
	a->arr[(a->front + 1) % a->size] = tmp;
	tmp = b->arr[b->front];
	b->arr[b->front] = b->arr[(b->front + 1) % a->size];
	b->arr[(b->front + 1) % a->size] = tmp;
	if (print)
	{
		write(1, "ss\n", 3);
		return (0);
	}
	return (ft_strdup("ss"));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:25:45 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/26 17:24:19 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	free_n_print_out(int flag, int print, void *a, void *b)
{
	if (flag == 1 || flag == 2)
	{
		if (a)
			free(a);
		if (b)
			free(b);
	}
	if (print == 1)
		ft_putstr_fd("Error\n", 2);
	if (flag == 2)
		return (-1);
	return (0);
}
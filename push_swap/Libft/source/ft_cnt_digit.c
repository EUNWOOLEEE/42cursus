/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:28:15 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/07 20:22:03 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_cnt_digit(int num)
{
	int	cnt;

	cnt = 0;
	if (!num)
		return (1);
	if (num == INT_MIN)
		return (11);
	if (num < 0)
	{
		cnt++;
		num *= -1;
	}
	while (num)
	{
		cnt++;
		num /= 10;
	}
	return (cnt);
}

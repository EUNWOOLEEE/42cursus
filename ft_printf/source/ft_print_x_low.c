/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:33:17 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/10 17:04:25 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	cnt_digit(unsigned int num)
{
	int	cnt;

	cnt = 0;
	if (!num)
		return (1);
	if (num < 0)
	{
		cnt++;
		num *= -1;
	}
	while (num)
	{
		cnt++;
		num /= 16;
	}
	return (cnt);
}

static char	*to_hex(unsigned int num)
{
	int		idx;
	char	*str;

	idx = cnt_digit(num);
	str = (char *)malloc(sizeof(char) * (idx + 1));
	if (!str)
		return (0);
	str[idx] = '\0';
	if (!num)
		str[0] = '0';
	while (num)
	{
		str[--idx] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	return (str);
}

char	*ft_print_x_low(void *arg)
{
	return (to_hex((unsigned int)arg));
}

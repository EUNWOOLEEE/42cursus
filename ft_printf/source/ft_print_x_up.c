/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:12:45 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/06 15:29:43 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	cnt_digit(unsigned int num)
{
	int	cnt;

	cnt = 0;
	if (!num)
		return (1);
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

char	*ft_print_x_up(va_list ap)
{
	char	*str;

	str = to_hex(va_arg(ap, unsigned int));
	if (str)
		ft_striteri(str, ft_toupper);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:33:23 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/10 16:41:23 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	cnt_digit(size_t num)
{
	int	cnt;

	cnt = 0;
	while (num)
	{
		cnt++;
		num /= 16;
	}
	return (cnt);
}

static char	*to_hex(size_t num)
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

ssize_t	ft_print_p(void *arg)
{
	int		cnt;
	char	*str;
	size_t	num;
	ssize_t	re;

	if (!arg)
		return (ft_putstr_fd("0x0", 1));
	num = (size_t)arg;
	str = to_hex(num);
	if (!str)
		return (-1);
	cnt = 0;
	re = ft_putstr_fd("0x", 1);
	if (re == -1)
	{
		free(str);
		return (-1);
	}
	else
		cnt += re;
	re = ft_putstr_fd(str, 1);
	if (re == -1)
	{
		free(str);
		return (-1);
	}
	else
		cnt += re;
	free(str);
	return (cnt);
}

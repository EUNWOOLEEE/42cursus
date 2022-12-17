/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:06:11 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/17 15:07:23 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int			idx;
	int			tmp1;
	size_t		tmp2;
	size_t		cnt;
	ssize_t		re;
	va_list		ap;

	idx = -1;
	cnt = 0;
	va_start(ap, fmt);
	while (fmt[++idx])
	{
		if (fmt[idx] != '%')
			re = ft_putchar_fd(fmt[idx], 1);
		else
		{
			idx++;
			if (fmt[idx] == '%')
				re = ft_putchar_fd('%', 1);
			else if (fmt[idx] == 's')
				re = get_string(fmt[idx], va_arg(ap, void *));
			else if (fmt[idx] == 'p')
			{
				tmp2 = va_arg(ap, size_t);
				re = get_string(fmt[idx], &tmp2);
			}
			else
			{
				tmp1 = va_arg(ap, int);
				if (fmt[idx] == 'c' && !tmp1)
					re = ft_putchar_fd('\0', 1);
				else
					re = get_string(fmt[idx], &tmp1);
			}
		}
		if (re == -1)
			return (-1);
		cnt += re;
	}
	return (cnt);
}

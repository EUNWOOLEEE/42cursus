/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:06:11 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/17 17:19:41 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int			idx;
	size_t		cnt;
	ssize_t		res;
	va_list		ap;

	idx = 0;
	cnt = 0;
	va_start(ap, fmt);
	while (fmt[idx])
	{
		if (fmt[idx] != '%')
			res = ft_putchar_fd(fmt[idx], 1);
		else
		{
			idx++;
			res = get_string(fmt[idx], &ap);
		}
		if (res == -1)
			return (-1);
		cnt += res;
		idx++;
	}
	va_end (ap);
	return (cnt);
}

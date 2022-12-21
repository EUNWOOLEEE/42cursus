/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:06:11 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/21 15:51:33 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int		idx;
	int		size;
	int		res;
	va_list	ap;

	idx = 0;
	size = 0;
	va_start(ap, fmt);
	while (fmt[idx])
	{
		if (fmt[idx] != '%')
			res = ft_putchar_fd(fmt[idx], 1);
		else
			res = get_string(fmt[++idx], ap);
		if (res == -1)
			return (-1);
		size += res;
		idx++;
	}
	va_end (ap);
	return (size);
}

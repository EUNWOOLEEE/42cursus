/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:06:11 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/10 16:42:38 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"

static int	get_format(char c)
{
	int		i;
	char	*fmt_list;

	i = 0;
	fmt_list = "cspdiuxX";
	while (fmt_list[i])
	{
		if (fmt_list[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static size_t	get_function(char c, void *arg)
{
	int	idx;

	ssize_t (*func_list[9])(void *);
	func_list[0] = ft_print_c;
	func_list[1] = ft_print_s;
	func_list[2] = ft_print_p;
	func_list[3] = ft_print_d;
	func_list[4] = ft_print_i;
	func_list[5] = ft_print_u;
	func_list[6] = ft_print_x_low;
	func_list[7] = ft_print_x_up;
	idx = get_format(c);
	if (idx == 1 && !arg)
		return (write (1, "(null)", 6));
	if (idx >= 0 && idx <= 7)
		return (func_list[idx](arg));
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	int			idx;
	size_t		cnt;
	ssize_t		re;
	va_list		ap;

	idx = 0;
	cnt = 0;
	va_start(ap, fmt);
	while (fmt[idx])
	{
		if (fmt[idx] != '%')
			re = write(1, &fmt[idx], 1);
		else
		{
			idx++;
			if (fmt[idx] == '%')
				re = ft_putchar_fd('%', 1);
			else if (ft_strchr("cspdiuxX", fmt[idx]))
				re = get_function(fmt[idx], va_arg(ap, void *));
			else
				re = write(1, &fmt[idx], 1);
		}
		if (re == -1)
			return (-1);
		cnt += re;
		idx++;
	}
	return (cnt);
}

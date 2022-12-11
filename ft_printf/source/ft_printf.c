/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:06:11 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/11 18:31:52 by eunwolee         ###   ########.fr       */
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

static char	*get_function(int fmt, void *arg)
{
	char	*(*func_list[9])(void *);

	func_list[0] = ft_print_c;
	func_list[1] = ft_print_s;
	func_list[2] = ft_print_p;
	func_list[3] = ft_print_d;
	func_list[4] = ft_print_i;
	func_list[5] = ft_print_u;
	func_list[6] = ft_print_x_low;
	func_list[7] = ft_print_x_up;
	if (fmt == 1 && !arg)
		return (ft_strdup("(null)"));
	if (fmt >= 0 && fmt <= 7)
		return (func_list[fmt](arg));
	return (0);
}

static ssize_t	get_str(char c, void *arg)
{
	int		fmt;
	char	*str;
	ssize_t	size;

	if (!arg && c == 'c')
		return (ft_putchar_fd('\0', 1));
	fmt = get_format(c);
	if (fmt == -1)
		return (ft_putchar_fd((char)arg, 1));
	str = get_function(fmt, arg);
	if (!str)
		return (-1);
	else
		size = ft_putstr_fd(str, 1);
	free (str);
	if (size == -1)
		return (-1);
	return (size);
}

int	ft_printf(const char *fmt, ...)
{
	int			idx;
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
			else
				re = get_str(fmt[idx], va_arg(ap, void *));
		}
		if (re == -1)
			return (-1);
		cnt += re;
	}
	return (cnt);
}

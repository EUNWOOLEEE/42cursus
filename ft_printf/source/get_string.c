/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:02:11 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/19 15:50:10 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_string(char fmt, va_list *ap)
{
	char	*str;
	char	*(*func)(va_list *);
	int		size;

	if (!ft_strchr("cspdiuxX", fmt))
		return (ft_putchar_fd(fmt, 1));
	func = get_function(fmt);
	str = func(ap);
	if (!str)
		return (-1);
	else if (!*str && fmt == 'c')
		size = ft_putchar_fd('\0', 1);
	else
		size = ft_putstr_fd(str, 1);
	free (str);
	if (size == -1)
		return (-1);
	return (size);
}

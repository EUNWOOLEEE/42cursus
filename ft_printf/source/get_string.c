/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:02:11 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/17 15:02:45 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

ssize_t	get_string(char fmt, void *arg)
{
	char	*str;
	char	*(*func)(void *);
	ssize_t	size;

	if (!arg && fmt == 's')
		return (ft_putstr_fd(0, 1));
	if (!ft_strchr("cspdiuxX", fmt))
		return (ft_putchar_fd(fmt, 1));
	func = get_function(fmt);
	str = func(arg);
	if (!str)
		return (-1);
	else
		size = ft_putstr_fd(str, 1);
	free (str);
	if (size == -1)
		return (-1);
	return (size);
}
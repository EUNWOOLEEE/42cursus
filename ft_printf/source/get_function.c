/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:34:56 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/21 15:51:53 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*(*get_function(char fmt))(va_list ap)
{
	if (fmt == 'c')
		return (ft_print_c);
	if (fmt == 's')
		return (ft_print_s);
	if (fmt == 'p')
		return (ft_print_p);
	if (fmt == 'd' || fmt == 'i')
		return (ft_print_d);
	if (fmt == 'u')
		return (ft_print_u);
	if (fmt == 'x')
		return (ft_print_x_low);
	if (fmt == 'X')
		return (ft_print_x_up);
	return (0);
}

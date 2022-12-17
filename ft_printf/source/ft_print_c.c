/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:04:54 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/17 17:18:08 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_print_c(va_list *ap)
{
	char	c;
	char	*str;

	c = (char)va_arg(*ap, int);
	if (!c)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (0);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

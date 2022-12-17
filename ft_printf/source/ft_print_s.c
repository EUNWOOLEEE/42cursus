/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:33:25 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/17 17:03:27 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_print_s(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

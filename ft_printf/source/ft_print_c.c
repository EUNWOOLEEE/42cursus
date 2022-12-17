/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:04:54 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/17 15:54:23 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_print_c(void *arg)
{
	char	*str;

	if (!arg)
		return (0);
	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (0);
	str[0] = *(char *)arg;
	str[1] = '\0';
	return (str);
}

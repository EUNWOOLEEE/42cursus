/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:33:20 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/10 14:25:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

ssize_t	ft_print_d(void *arg)
{
	char	*dest;
	ssize_t	re;

	dest = ft_itoa_d((int)arg);
	if (!dest)
		return (-1);
	re = ft_putstr_fd(dest, 1);
	free(dest);
	return (re);
}

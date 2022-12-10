/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:11:23 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/10 14:28:25 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

ssize_t	ft_print_u(void *arg)
{
	char	*dest;
	ssize_t	re;

	dest = ft_itoa_u((unsigned int)arg);
	if (!dest)
		return (-1);
	re = ft_putstr_fd(dest, 1);
	free(dest);
	return (re);
}

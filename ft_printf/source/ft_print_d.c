/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:33:20 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/17 15:06:29 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_print_d(void *arg)
{
	int		tmp;
	long	num;

	tmp = *(int *)arg;
	num = (long)tmp;
	return (ft_itoa_d(num));
}

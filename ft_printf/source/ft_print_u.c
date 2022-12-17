/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:11:23 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/17 15:06:58 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_print_u(void *arg)
{
	int				tmp;
	unsigned int	num;

	tmp = *(int *)arg;
	num = (unsigned int)tmp;

	return (ft_itoa_u(num));
}

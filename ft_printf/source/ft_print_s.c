/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:33:25 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/11 14:46:17 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char	*ft_print_s(void *arg)
{
	return (ft_strdup((const char *)arg));
}

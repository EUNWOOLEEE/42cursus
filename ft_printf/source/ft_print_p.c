/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:33:23 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/17 17:05:05 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	cnt_digit(size_t num)
{
	int	cnt;

	cnt = 0;
	while (num)
	{
		cnt++;
		num /= 16;
	}
	return (cnt);
}

static char	*to_hex_p(size_t num)
{
	int		idx;
	char	*str;

	if (!num)
		return (ft_strdup("0x0"));
	idx = 3;
	idx += cnt_digit(num);
	str = (char *)malloc(sizeof(char) * (idx));
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = 'x';
	str[--idx] = '\0';
	while (num)
	{
		str[--idx] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	return (str);
}

char	*ft_print_p(va_list *ap)
{
	return (to_hex_p(va_arg(*ap, size_t)));
}

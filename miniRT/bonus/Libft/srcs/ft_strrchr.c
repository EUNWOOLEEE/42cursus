/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:11:16 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/25 08:24:40 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*tmp;
	unsigned char	ch;

	tmp = 0;
	ch = (unsigned char) c;
	while (*s)
	{
		if (*s == ch)
			tmp = s;
		s++;
	}
	if (*s == ch)
		tmp = s;
	return ((char *)tmp);
}

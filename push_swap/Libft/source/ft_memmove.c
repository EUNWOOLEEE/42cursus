/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:43:24 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/09 18:19:40 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;

	if (!dst && !src)
		return (0);
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	if (dest > source)
		while (len--)
			*(dest + len) = *(source + len);
	else
		while (len--)
			*dest++ = *source++;
	return (dst);
}

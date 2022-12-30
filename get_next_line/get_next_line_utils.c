/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:01:47 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/28 18:52:36 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_strncat(char *dest, char *src, int size)
{
	while (*dest)
		dest++;
	while (*src && size)
	{
		*dest++ = *src++;
		size--;
	}
	*dest = '\0';
}

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char		*dest;
	unsigned char	*source;

	if (!dst && !src)
		return (0);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dest > source)
		while (len--)
			*(dest + len) = *(source + len);
	else
		while (len--)
			*dest++ = *source++;
	return (dst);
}

char	*ft_strchr(char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(char *s1)
{
	size_t		len;
	char		*dest;

	len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, len + 1);
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		idx;
	char	*str;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	idx = 0;
	while (*s1)
		str[idx++] = *s1++;
	while (*s2)
		str[idx++] = *s2++;
	str[idx] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(src);
	if (!dstsize)
		return (len);
	while (*src && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (len);
}

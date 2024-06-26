/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:55:14 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/27 16:52:32 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*tmp;
	size_t		idx;
	size_t		size;

	if (start > ft_strlen(s))
		size = 0;
	else if (len > ft_strlen(s + start))
		size = ft_strlen(s + start);
	else
		size = len;
	tmp = (char *)ft_calloc(size + 1, sizeof(char));
	if (!tmp)
		return (0);
	idx = 0;
	if (size)
		while (idx < len && s[start])
			tmp[idx++] = s[start++];
	tmp[idx] = '\0';
	return (tmp);
}

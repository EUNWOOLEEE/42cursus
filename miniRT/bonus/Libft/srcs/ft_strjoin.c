/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:57:36 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/25 08:23:35 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		idx;
	char	*str;

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

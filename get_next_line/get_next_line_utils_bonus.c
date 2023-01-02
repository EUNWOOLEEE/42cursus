/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:01:47 by eunwolee          #+#    #+#             */
/*   Updated: 2023/01/02 16:44:38 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
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

char	*ft_strdup(char *str)
{
	size_t		i;
	size_t		len;
	char		*dest;

	len = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
	dest[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
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

char	*delete_nod(t_list **head, t_list *nod)
{
	while ((*head)->next->fd != nod->fd)
		*head = (*head)->next;
	(*head)->next = nod->next;
	free(nod);
	return (0);
}

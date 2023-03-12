/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:01:47 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/12 16:11:44 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		idx;
	char	*str;
	char	*tmp;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
	{
		free(s1);
		return (0);
	}
	idx = 0;
	tmp = s1;
	while (*s1)
		str[idx++] = *s1++;
	while (*s2)
		str[idx++] = *s2++;
	str[idx] = '\0';
	free(tmp);
	return (str);
}

char	*delete_nod(t_gnl_list **head, t_gnl_list *nod)
{
	t_gnl_list	*tmp;

	tmp = *head;
	if (tmp == nod)
	{
		if (!(tmp->next))
			*head = 0;
		else
			*head = tmp->next;
		free(nod->buff);
		free(nod);
		return (0);
	}
	while (tmp->next != nod)
		tmp = tmp->next;
	tmp->next = nod->next;
	free(nod->buff);
	free(nod);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:52:44 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/10 16:04:45 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	cnt_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static int	cnt_str(char const *s, int c)
{
	int	cnt;
	int	len;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = cnt_len(s, c);
			cnt++;
			s += len;
		}
	}
	return (cnt);
}

static char	*str_dup(char const *s, int size)
{
	int		idx;
	char	*dest;

	idx = 0;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (0);
	while (size--)
		dest[idx++] = *s++;
	dest[idx] = '\0';
	return (dest);
}

static char	**clear(char **dest, int idx)
{
	while (idx--)
		free (dest[idx]);
	free (dest);
	return (0);
}

char	**ft_split(char const *s, char c, int *cmds_size)
{
	int		idx;
	int		size;
	char	**dest;

	dest = (char **)malloc(sizeof(char *) * (cnt_str(s, c) + 1));
	if (!dest)
		return (0);
	idx = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			size = cnt_len(s, c);
			dest[idx] = str_dup(s, size);
			if (!dest[idx])
				return (clear(dest, idx));
			s += size;
			idx++;
		}
	}
	dest[idx] = 0;
	*cmds_size = idx;
	return (dest);
}

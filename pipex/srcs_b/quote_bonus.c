/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:48:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/27 17:44:31 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int			check_quote(char *str);
char		**split_quote(char *s, char c, int cnt);
static int	cnt_str(char const *s, int c);
static int	exe_split(char **dest, const char *s, int *idx, int size);
static int	cnt_len_q(char const *s);

int	check_quote(char *str)
{
	int		idx;
	int		cnt;
	t_bool	quote;

	idx = 0;
	cnt = 0;
	quote = FALSE;
	while (str[idx])
	{
		if (str[idx] == '\'' || str[idx] == '\"')
		{
			if (quote == FALSE)
			{
				quote = TRUE;
				cnt++;
			}
			else
				quote = FALSE;
		}
		idx++;
	}
	if (quote == TRUE)
		print_error("Invalid quote");
	return (cnt);
}

char	**split_quote(char *s, char c, int cnt)
{
	int		idx;
	char	**dest;

	cnt += cnt_str(s, c);
	dest = (char **)ft_calloc(cnt + 1, sizeof(char *));
	if (!dest)
		return (0);
	if (!cnt)
		dest[0] = ft_strdup("");
	else
	{
		idx = 0;
		if (exe_split(dest, s, &idx, 0) == -1)
			return (clear(dest, idx));
	}
	return (dest);
}

static int	exe_split(char **dest, const char *s, int *idx, int size)
{
	while (*s)
	{
		if (*s == ' ')
		{
			s++;
			continue ;
		}
		if (*s == '\'' || *s == '\"')
		{
			s++;
			size = cnt_len_q(s);
			dest[*idx] = ft_substr(s, 0, size);
			s++;
		}
		else
		{
			size = cnt_len(s, ' ');
			dest[*idx] = ft_substr(s, 0, size);
		}
		if (!dest[*idx])
			return (-1);
		s += size;
		*idx += 1;
	}
	return (0);
}

static int	cnt_str(char const *s, int c)
{
	int		cnt;
	int		len;

	cnt = 0;
	while (*s)
	{
		if (*s == '\'' || *s == '\"')
		{
			s++;
			while (*s && (*s != '\'' || *s != '\"'))
				s++;
			s++;
		}
		else if (*s == c)
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

static int	cnt_len_q(char const *s)
{
	int	len;

	len = 0;
	while (s[len] != '\'' && s[len] != '\"')
	{
		len++;
		if (s[len] == '\0')
			print_error("Invalid quote");
	}
	return (len);
}

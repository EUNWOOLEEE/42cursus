/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:48:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/21 14:20:25 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_bool		check_quote(char *str);
char		**split_quote(char *s, char c, t_bool quote, int idx);
static void	set_quote(char **s, t_bool *quote, t_bool set);
static int	cnt_len(char const *s, char c, t_bool *quote);
static int	cnt_str(char const *s, int c);

t_bool	check_quote(char *str)
{
	if (ft_strchr(str, '\'') || ft_strchr(str, '\"'))
		return (TRUE);
	return (FALSE);
}

char	**split_quote(char *s, char c, t_bool quote, int idx)
{
	int		size;
	char	**dest;

	dest = (char **)ft_calloc(1, sizeof(char *) * (cnt_str(s, c)));
	if (!dest)
		return (0);
	while (*s)
	{
		if (quote == FALSE && (*s == '\'' || *s == '\"'))
			set_quote(&s, &quote, TRUE);
		if (*s == c)
			s++;
		else
		{
			size = cnt_len(s, c, &quote);
			dest[idx] = ft_substr(s, 0, size);
			if (quote == TRUE)
				set_quote(&s, &quote, FALSE);
			if (!dest[idx])
				return (clear(dest, idx));
			s += size;
			idx++;
		}
	}
	return (dest);
}

static void	set_quote(char **s, t_bool *quote, t_bool set)
{
	*s += 1;
	*quote = set;
}

static int	cnt_len(char const *s, char c, t_bool *quote)
{
	int	len;

	len = 0;
	if (*quote == TRUE)
	{
		len++;
		while ((s[len] != '\'' && s[len] != '\"') && s[len])
			len++;
	}
	else
		while (s[len] != c && s[len])
			len++;
	return (len);
}

static int	cnt_str(char const *s, int c)
{
	int		cnt;
	int		len;
	t_bool	quote;

	cnt = 0;
	quote = FALSE;
	while (*s)
	{
		if (quote == FALSE && (*s == '\'' || *s == '\"'))
			quote = TRUE;
		else if (quote == TRUE && (*s == '\'' || *s == '\"'))
			quote = FALSE;
		if (*s == c)
			s++;
		else
		{
			len = cnt_len(s, c, &quote);
			cnt++;
			s += len;
		}
	}
	return (cnt);
}

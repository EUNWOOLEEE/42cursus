/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:48:41 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/25 16:08:55 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_bool		check_quote(char *str, int **num);
char		**split_quote(char *s, char c, int num);
static void	set_quote(const char **s, t_bool *quote, t_bool set);
static int	cnt_len(char const *s, char c, t_bool *quote);
static int	cnt_str(char const *s, int c);
static int	exe_split(char **dest, const char *s, char c, int *idx);

t_bool	check_quote(char *str, int **num)
{
	int	idx;

	num[0] = 0;
	num[1] = 0;
	idx = 0;
	while (str[idx])
	{
		if (ft_strchr(&str[idx], '\''))
			num[0]++;
		else if (ft_strchr(str, '\"'))
			num[1]++;
		idx++;
	}
	if (num[0] || num[1])
		return (TRUE);
	return (FALSE);
}

char	* *split_quote(char *s, char c, int num)
{
	int		idx;
	int		cnt;
	char	**dest;

	cnt = cnt_str(s, c);
	printf("%d\n", cnt);
	dest = (char **)ft_calloc(cnt + 1, sizeof(char *));
	if (!dest)
		return (0);
	if (!cnt)
		dest[0] = ft_strdup("");
	else
	{
		idx = 0;
		if (exe_split(dest, s, c, &idx) == -1)
			return (clear(dest, idx));
	}
	return (dest);
}

static int	exe_split(char **dest, const char *s, char c, int *idx)
{
	int		size;
	t_bool	quote;

	*idx = 0;
	quote = FALSE;
	while (*s)
	{
		if (quote == FALSE && (*s == '\'' || *s == '\"'))
			set_quote(&s, &quote, TRUE);
		else if (*s == c)
			s++;
		else
		{
			size = cnt_len(s, c, &quote);
			dest[*idx] = ft_substr(s, 0, size);
			if (quote == TRUE)
				set_quote(&s, &quote, FALSE);
			if (!dest[*idx])
				return (-1);
			s += size;
			*idx += 1;
		}
	}
	if (quote == TRUE)
		print_error("Invalid quote");
	return (0);
}

static void	set_quote(const char **s, t_bool *quote, t_bool set)
{
	*s += 1;
	*quote = set;
}

static int	cnt_len(char const *s, char c, t_bool *quote)
{
	int	len;

	len = 0;
	if (*quote == TRUE)
		while ((s[len] != '\'' && s[len] != '\"') && s[len])
			len++;
	else
		while ((s[len] != '\'' && s[len] != '\"' && s[len] != c) && s[len])
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
			set_quote(&s, &quote, TRUE);
		else if (quote == TRUE && (*s == '\'' || *s == '\"'))
			set_quote(&s, &quote, FALSE);
		else if (*s == c)
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

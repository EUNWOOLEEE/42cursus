/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:16:20 by eunwolee          #+#    #+#             */
/*   Updated: 2023/08/17 21:32:54 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void		write_str(t_data *data, char *content, int fd);
static void	heredoc_parser(t_data *data, int fd, char *str);
static char	*heredoc_question(t_data *data, char *tmp, int *i);
static char	*heredoc_expand(t_data *data, char *str, char *tmp, int *i);
static void	heredoc_replace(t_data *data, char **tmp, char *name);

void	write_str(t_data *data, char *content, int fd)
{
	char	*str;

	while (1)
	{
		str = readline ("> ");
		if (!str \
			|| (!ft_strncmp (content, str, ft_strlen(content)) && \
			(ft_strlen(content) == (ft_strlen(str)))))
		{
			free (str);
			close (fd);
			return ;
		}
		heredoc_parser(data, fd, str);
	}
}

static void	heredoc_parser(t_data *data, int fd, char *str)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = ft_strdup("");
	while (str[++i])
	{
		if (str[i] == '$')
		{
			if (str[i + 1] == '?')
				tmp = heredoc_question(data, tmp, &i);
			else
				tmp = heredoc_expand(data, str, tmp, &i);
		}
		else
			tmp = ft_strncat(tmp, &str[i], 1);
	}
	write (fd, tmp, ft_strlen(tmp));
	write (fd, "\n", 1);
	free (str);
}

static char	*heredoc_question(t_data *data, char *tmp, int *i)
{
	char	*temp;

	(void) data;
	temp = ft_itoa(g_error_code);
	tmp = ft_strncat(tmp, temp, ft_strlen(temp));
	*i += 1;
	return (tmp);
}

static char	*heredoc_expand(t_data *data, char *str, char *tmp, int *i)
{
	char	*name;

	*i += 1;
	name = ft_strdup("");
	while (str[*i] != '\0' && str[*i] != ' ' && str[*i] != '\t')
	{
		name = ft_strncat(name, &str[*i], 1);
		*i += 1;
	}
	heredoc_replace(data, &tmp, name);
	if (str[*i] != '\0')
		*i -= 1;
	return (tmp);
}

static void	heredoc_replace(t_data *data, char **tmp, char *name)
{
	int		j;
	t_list	*env;

	env = env_search(data, name, TRUE);
	if (!env)
	{
		*tmp = ft_strncat(*tmp, "$", 1);
		*tmp = ft_strncat(*tmp, name, ft_strlen(name));
	}
	else
	{
		j = 0;
		while (env->env[j] != '=')
			j++;
		*tmp = ft_strncat(*tmp, \
			&env->env[j + 1], ft_strlen(&env->env[j + 1]));
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:00 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/06 21:34:22 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char **get_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	path = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
		{
			path = ft_split(&envp[i][5], ':');
			break;
		}
		i++;
	}
	return (path);
}

void get_elements(char **argv)
{
	
}

int main(int argc, char **argv, char **envp)
{
	pid_t pid;
	t_elements *elements;

	elements = (t_elements *)ft_calloc(1, sizeof(t_elements));
	pid = fork();
	path = get_path(envp);
	(void)argv;

	if (argc != 5)
		return (0); //error
	return (0);
}
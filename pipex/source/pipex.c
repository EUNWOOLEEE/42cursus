/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:00 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/07 20:59:56 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// ./pipex infile ``ls -l'' ``wc -l'' outfile
// < file1 cmd1 | cmd2 > file2

void	get_path(t_elements *elements, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
		{
			elements->path = ft_split(&envp[i][5], ':');
			break;
		}
		i++;
	}
	if (!elements->path)
		return ;
}

void get_element(t_elements *elements, char **argv)
{
	elements->fd[0] = open(argv[1], O_RDONLY);
	elements->fd[1] = open(argv[4], O_RDWR | O_CREAT, S_IRUGO | S_IWUSR);
	if (elements->fd[0] == -1 || elements->fd[1] == -1)
		return ; //error
	elements->cmd1 = ft_split(argv[2], ' ');
	elements->cmd2 = ft_split(argv[3], ' ');
	if (!elements->cmd1 || !elements->cmd2)
		return ; //error
}

void	execute_cmd(t_elements *elements, char **envp)
{
	int	i;
	int	res;
	char *tmp;
	char *path;

	i = 0;
	res = -1;
	while (elements->path[i])
	{
		tmp = ft_strjoin(elements->path[i], "/");
		path = ft_strjoin(tmp, elements->cmd1[0]);
		res = execve(path, elements->cmd1, envp);
		free(tmp);
		free(path);
		i++;
	}
}

int main(int argc, char **argv, char **envp)
{
	t_elements *elements;
	
	if (argc != 5)
		return (0); //error
	elements = (t_elements *)ft_calloc(1, sizeof(t_elements));
	get_path(elements, envp);
	get_element(elements, argv);
	if (pipe(elements->fd) == -1)
		return (0); //error
	elements->pid = fork();
	if(!elements->pid) //자식에서 cmd1 실행
	{
		close(elements->fd[P_WRITE]);
		execute_cmd(elements, envp);
		close(elements->fd[P_READ]);
	}

	return (0);
}
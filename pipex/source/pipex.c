/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:00 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/10 11:34:41 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// ./pipex infile ``ls -l'' ``wc -l'' outfile
// < file1 cmd1 | cmd2 > file2

t_bool print_error(char **cmd, int errno)
{
	char *err;
	(void)cmd;

	err = strerror(errno);
	printf("%s\n", err);
	return (FALSE);
}

void get_path(t_elements *elements, char **envp)
{
	int i;

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
		return;
}

void get_element(t_elements *elements, char **argv, int errno)
{
	(void)errno;
	elements->fd1 = open(argv[1], O_RDONLY);
	elements->fd2 = open(argv[4], O_RDWR | O_CREAT, S_IRUGO | S_IWUSR);
	// if (elements->fd1 == -1 || elements->fd2 == -1) error
	elements->cmd1 = ft_split(argv[2], ' ');
	elements->cmd2 = ft_split(argv[3], ' ');
	if (!elements->cmd1 || !elements->cmd2)
		return; // error
}

t_bool execute_cmd(char **path_lst, char **cmd, char **envp, int errno)
{
	int i;
	int res;
	int acs;
	char *tmp;
	char *path;
	char *err;

	i = 5;
	res = -1;
	while (path_lst[i])
	{
		if (access(path_lst[i], F_OK) == -1) //클러스터 맥에서도 필요한 부분인가?
		{
			i++;
			continue;
		}
		tmp = ft_strjoin(path_lst[i], "/");
		path = ft_strjoin(tmp, cmd[0]);
		printf("%s\n", path); //왜 errno가 2가 아니라 22지??
		printf("%d %s\n", errno, strerror(errno));
		acs = access(path, X_OK);
		printf("%d\n", acs);
		if (!acs)
		{
			res = execve(path, cmd, envp);
			if (res == -1)
			{
				// err = ft_strjoin(cmd[0], cmd[1]);
				printf("%s\n", strerror(errno));
				return (FALSE);
			}
			break;
		}
		i++;
		if (!path_lst[i])
			err = strerror(errno);
		free(tmp);
		free(path);
	}
	if (acs == -1)
		printf("%s\n", err);
		// return (print_error(cmd, errno));
	return (TRUE);
}

void wait_child_n_execute(t_elements *elements, char **envp, int errno)
{
	int status;

	waitpid(elements->pid, &status, WNOHANG);
	close(elements->fd[P_WRITE]);
	dup2(elements->fd[P_READ], STDIN_FILENO);
	dup2(elements->fd2, STDOUT_FILENO);
	execute_cmd(elements->path, elements->cmd2, envp, errno);
}

int main(int argc, char **argv, char **envp)
{
	extern int errno;
	t_elements *elements;

	if (argc != 5)
		return (0); // error
	errno = 0;
	elements = (t_elements *)ft_calloc(1, sizeof(t_elements));
	get_path(elements, envp);
	printf("%d\n", errno);
	get_element(elements, argv, errno);
	if (pipe(elements->fd) == -1)
		return (0); // error
	elements->pid = fork();
	if (!elements->pid) // 자식에서 cmd1 실행
	{
		close(elements->fd[P_READ]);
		dup2(elements->fd1, STDIN_FILENO);
		// dup2(elements->fd[P_WRITE], STDOUT_FILENO);
		execute_cmd(elements->path, elements->cmd1, envp, errno);
	}
	wait_child_n_execute(elements, envp, errno);
	return (0);
}
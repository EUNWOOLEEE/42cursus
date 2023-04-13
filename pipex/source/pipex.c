/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:00 by eunwolee          #+#    #+#             */
/*   Updated: 2023/04/13 18:36:21 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// ./pipex infile ``ls -l'' ``wc -l'' outfile
// < file1 cmd1 | cmd2 > file2

// t_bool execute_cmd(char **path_lst, char **cmd, char **envp)
// {
// 	int i;
// 	int res;
// 	int acs;
// 	char *tmp;
// 	char *path;
// 	char *err;

// 	i = 0;
// 	res = -1;
// 	while (path_lst[i]) //절대경로 추가 ./
// 	{
// 		if (access(path_lst[i], F_OK) == -1) //클러스터 맥에서도 필요한 부분인가?
// 		{
// 			i++;
// 			continue;
// 		}
// 		tmp = ft_strjoin(path_lst[i], "/");
// 		path = ft_strjoin(tmp, cmd[0]);
// 		// printf("path: %s\n", path); //왜 errno가 2가 아니라 22지??
// 		// printf: %d, errstr: %s\n", strerror(errno)));
// 		acs = access(path, X_OK);
// 		// printf("acs: %d\n", acs);
// 		if (!acs)
// 		{
// 			res = execve(path, cmd, envp);
// 			if (res == -1)
// 			{
// 				// err = ft_strjoin(cmd[0], cmd[1]);
// 				printf("%s\n", strerror(errno));
// 				return (FALSE);
// 			}
// 			break;
// 		}
// 		i++;
// 		if (!path_lst[i])
// 			err = strerror(errno);
// 		free(tmp);
// 		free(path);
// 	}
// 	if (acs == -1) //exit
// 		printf("%s\n", err);
// 		// return (print_error(cmd));
// 	return (TRUE);
// }

// void wait_child_n_execute(t_data *data, char **envp)
// {
// 	int status;

// 	waitpid(data->pid, &status, WNOHANG);
// 	close(data->fd[P_WRITE]);
// 	dup2(data->fd[P_READ], STDIN_FILENO);
// 	dup2(data->outfile, STDOUT_FILENO);
// 	execute_cmd(data->path, data->cmd2, envp);
// }

int main(int argc, char **argv, char **envp)
{
	int	turn;
	int status;
	t_data *data;

	// if (argc != 5) //보너스는 5 미만으로 바꾸기
	// 	return (0); // error
	init_data(&data, argc, argv, envp);
	// if (!data->pid) // 자식에서 cmd1 실행
	// {
	// 	close(data->fd[P_READ]);
	// 	dup2(data->infile, STDIN_FILENO);
	// 	dup2(data->fd[P_WRITE], STDOUT_FILENO);
	// 	execute_cmd(data->path, data->cmd1, envp);
	// }
	
	turn = 0;
	while (turn < data->cmd_num)
	{
		data->cur_pid = fork();
		if (data->cur_pid == -1)
			print_error("Fork failure");
		if (!data->cur_pid) //child
		{
			close(data->cmd[turn].fd[P_READ]);
			return (0);
		}
		data->cmd[turn].pid = data->cur_pid;
		waitpid(data->cmd[turn].pid, &status, WNOHANG);
		turn++;
	}
	// wait_child_n_execute(data, envp);
	return (0);
}

//옵션으로 줄때 awk 같은 경우 싱글쿼트 없애기??
//쿼트 들어오는 함수?
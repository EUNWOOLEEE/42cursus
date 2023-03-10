/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:21:04 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/09 18:18:46 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

int act_cmd(char *cmds)
{
	char cmd[4];
	int idx;
}

int main(int argc, char **argv)
{
	int size;
	char *cmds;

	size = check_valid(argv);
	if (argc == 1 || size <= 0)
		return (free_n_print_out(0, 1, 0, 0));
	cmds = get_next_line(0);
	while (cmds)
	{
		act_cmd(cmds);
		cmds = get_next_line(0);
	}
}
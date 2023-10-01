/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:07:02 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/28 12:35:32 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int main(int argc, char **argv)
{
	t_info	*info;
	
	info = init_info(argc, argv[1]);
	read_info(info);

	print_infos(info);
	return (0);
}
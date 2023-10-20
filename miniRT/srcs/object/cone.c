/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:19:12 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/18 18:42:13 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_cone	*cone(char **strs)
{
	t_cone	*co;

	(void)strs;
	// if (cnt_strs(strs) != 6)
		// print_error_exit(USAGE_CO);
	co = (t_cone *)ft_calloc(1, sizeof(t_cone));
	if (!co)
		print_error_exit(MEMORY);
	return (co);
}
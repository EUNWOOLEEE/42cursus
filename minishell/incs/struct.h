/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 07:22:04 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/08 11:18:19 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "hash.h"
# include "tree.h"
# include "parse.h"

typedef struct s_data
{
	t_bucket	*env;
	int			table_size;
	char		*input;
	t_list		*tokens;
	t_leaf		*root;
}	t_data;


#endif
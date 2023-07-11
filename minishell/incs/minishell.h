/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:05:33 by eunwolee          #+#    #+#             */
/*   Updated: 2023/07/11 08:03:47 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
// # include "hash.h"
# include "tree.h"
# include "parse.h"
# include "struct.h"
# include "../Libft/libft.h"
// #include <readline/readline.h>
// #include <readline/history.h>

/*init*/
bool	init(t_data **data, char **envp);

bool	env_init(t_data *data, char **envp);
void	env_print(t_data *data);
t_list	*env_search(t_data *data, char *key);
bool	env_remove(t_data *data, char *key);

t_list	*ft_lstnew(void);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
int		ft_lstsize(t_list *lst);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:00:01 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/10 22:10:19 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define BUFFER_SIZE 42
typedef struct s_gnl_list
{
	int					fd;
	char				*buff;
	struct s_gnl_list	*next;
}	t_gnl_list;

typedef struct s_list
{
	char 			*cmd;
	struct s_list	*next;
}	t_list;

long long	ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);

int			ft_isdigit(int c);
int			ft_cnt_digit(int num);
void		ft_putstr_fd(char *s, int fd);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);

void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(char *cmd);

char		*get_next_line(int fd);
char		*ft_strchr(char *s, char c);
char		*ft_strjoin(char *s1, char *s2);
char		*delete_nod(t_gnl_list **head, t_gnl_list *nod);
char		**ft_split(char const *s, char c, int *cmds_size);


#endif
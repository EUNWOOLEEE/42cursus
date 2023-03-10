/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:00:01 by eunwolee          #+#    #+#             */
/*   Updated: 2023/03/09 18:23:29 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define BUFFER_SIZE 20
typedef struct s_list
{
	int				fd;
	char			*buff;
	struct s_list	*next;
}	t_list;

long long	ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isdigit(int c);
int			ft_cnt_digit(int num);
void		ft_putstr_fd(char *s, int fd);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*get_next_line(int fd);
char		*ft_strchr(char *s, char c);
char		*ft_strjoin(char *s1, char *s2);
char		*delete_nod(t_list **head, t_list *nod);
char		**ft_split(char const *s, char c);

#endif
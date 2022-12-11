/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:08:22 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/11 14:50:05 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(char *));
void	ft_toupper(char *c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa_d(int n);
char	*ft_itoa_u(unsigned int n);
char	*ft_strdup(const char *s1);

#endif
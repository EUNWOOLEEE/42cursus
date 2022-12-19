/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:08:22 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/19 15:53:08 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
void	ft_striteri(char *s, void (*f)(char *));
void	ft_toupper(char *c);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa_d(int arg);
char	*ft_itoa_u(unsigned int arg);

#endif
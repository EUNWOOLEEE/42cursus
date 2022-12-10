/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:53:40 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/10 13:53:53 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "../Libft/includes/libft.h"

int		ft_printf(const char *fmt, ...);
ssize_t	ft_print_c(void *arg);
ssize_t	ft_print_s(void *arg);
ssize_t	ft_print_p(void *arg);
ssize_t	ft_print_d(void *arg);
ssize_t	ft_print_i(void *arg);
ssize_t	ft_print_u(void *arg);
ssize_t	ft_print_x_low(void *arg);
ssize_t	ft_print_x_up(void *arg);

// int		ft_printf(const char *fmt, ...);
// size_t	ft_print_c(char c);
// size_t	ft_print_s(char *s);
// size_t	ft_print_p(size_t num);
// size_t	ft_print_d(int num);
// size_t	ft_print_i(int num);
// size_t	ft_print_u(unsigned int num);
// size_t	ft_print_x_low(long num);
// size_t	ft_print_x_up(long num);

#endif
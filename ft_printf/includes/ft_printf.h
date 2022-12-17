/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:53:40 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/17 15:09:20 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../Libft/includes/libft.h"

int		ft_printf(const char *fmt, ...);
char	*ft_print_c(void *arg);
char	*ft_print_s(void *arg);
char	*ft_print_p(void *arg);
char	*ft_print_d(void *arg);
char	*ft_print_u(void *arg);
char	*ft_print_x_low(void *arg);
char	*ft_print_x_up(void *arg);
char	*(*get_function(char fmt))(void *);
ssize_t	get_string(char fmt, void *arg);

#endif
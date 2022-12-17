/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:53:40 by eunwolee          #+#    #+#             */
/*   Updated: 2022/12/17 16:36:45 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../Libft/includes/libft.h"

int		ft_printf(const char *fmt, ...);
char	*ft_print_c(va_list *ap);
char	*ft_print_s(va_list *ap);
char	*ft_print_p(va_list *ap);
char	*ft_print_d(va_list *ap);
char	*ft_print_u(va_list *ap);
char	*ft_print_x_low(va_list *ap);
char	*ft_print_x_up(va_list *ap);
char	*(*get_function(char fmt))(va_list *ap);
ssize_t	get_string(char fmt, va_list *ap);

#endif
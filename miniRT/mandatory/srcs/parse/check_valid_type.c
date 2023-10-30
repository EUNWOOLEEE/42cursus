/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:28:27 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/30 15:30:28 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_bool	check_ratio(double ratio);
t_bool	check_color(t_color color);
t_bool	check_vector(t_vec vector);
t_bool	check_int_char(char *str);
t_bool	check_double_char(char *str);

t_bool	check_ratio(double ratio)
{
	if (ratio < 0.0 || 1.0 < ratio)
		return (FALSE);
	return (TRUE);
}

t_bool	check_color(t_color color)
{
	if (color.x < 0 || 255 < color.x \
		|| color.y < 0 || 255 < color.y \
		|| color.z < 0 || 255 < color.z)
		return (FALSE);
	return (TRUE);
}

t_bool	check_vector(t_vec vector)
{
	if (vector.x < -1 || 1 < vector.x \
		|| vector.y < -1 || 1 < vector.y \
		|| vector.z < -1 || 1 < vector.z)
		return (FALSE);
	if (!vector.x && !vector.y && !vector.z)
		return (FALSE);
	return (TRUE);
}

t_bool	check_int_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]) && str[i] != '\n')
			return (FALSE);
	return (TRUE);
}

t_bool	check_double_char(char *str)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	if (str[i + 1] == '-')
		i = 0;
	while (str[++i])
	{
		if (str[i] == '.')
			cnt++;
		if ((!ft_isdigit(str[i]) && str[i] != '.' && str[i] != '\n') \
			|| cnt > 1)
			return (FALSE);
	}
	return (TRUE);
}

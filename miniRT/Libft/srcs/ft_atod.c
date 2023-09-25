/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:20:40 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/25 08:53:00 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	convert_above(const char **str);
static double	convert_below(const char *str);

double	ft_atod(const char *str)
{
	double	sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return ((convert_above(&str) + convert_below(str)) * sign);
}

static double	convert_above(const char **str)
{
	double	res;

	res = 0;
	while (**str >= '0' && **str <= '9')
	{
		res = (res * 10) + (**str - '0');
		*str += 1;
	}
	return (res);
}

static double	convert_below(const char *str)
{
	int		i;
	int		idx;
	double	res;
	double	tmp;
	
	idx = 0;
	res = 0;
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			idx++;
			i = 0;
			tmp = *str++ - '0';
			while (i < idx)
			{
				tmp /= 10;
				i++;
			}
			res += tmp;
		}
	}
	return (res);
}

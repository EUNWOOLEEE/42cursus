/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:15:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/03 19:53:28 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void		*ft_calloc(size_t count, size_t size);
uint64_t	ft_atoi(char *str, bool *state);
bool		all_free(t_philo **philo, t_info **info);

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = malloc(size * count);
	if (!tmp)
		return (0);
	memset(tmp, 0, size * count);
	return (tmp);
}

uint64_t	ft_atoi(char *str, bool *state)
{
	int64_t	res;
	int64_t	sign;

	res = 0;
	sign = 1;
	*state = false;
	if (*str == '\0')
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	res *= sign;
	if (res >= 0)
		*state = true;
	return ((uint64_t)res);
}

bool	all_free(t_philo **philo, t_info **info)
{
	int	error;
	int	i;

	error = (*info)->error;
	i = 0;
	while (i < (*info)->num_philo)
	{
		pthread_mutex_destroy(&(*info)->fork[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&(*info)->print);
	free((*info)->fork);
	free(*info);
	free(*philo);
	*info = 0;
	*philo = 0;
	return (error);
}

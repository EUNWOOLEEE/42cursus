/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:15:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/05 08:24:51 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(char *str);
bool	print_error(char *str);
bool	all_free(t_philo **philo, t_info **info);

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = malloc(size * count);
	if (!tmp)
		return (0);
	memset(tmp, 0, size * count);
	return (tmp);
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
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
	return (res * sign);
}

bool	print_error(char *str)
{
	printf("\033[31mError\033[0m\n");
	printf("\033[36m%s\033[0m\n", str);
	return (false);
}

bool	all_free(t_philo **philo, t_info **info)
{
	int	error;
	int	i;

	error = (*info)->error;
	i = -1;
	while (++i < (*info)->num_philo)
		pthread_mutex_destroy(&(*info)->fork[i].mutex);
	pthread_mutex_destroy(&(*info)->print);
	pthread_mutex_destroy(&(*info)->start);
	free((*info)->fork);
	free(*info);
	free(*philo);
	*info = 0;
	*philo = 0;
	return (error);
}

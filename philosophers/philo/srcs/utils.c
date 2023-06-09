/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:15:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/09 15:20:24 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(char *str);
bool	ft_mutex_unlock(pthread_mutex_t *a, pthread_mutex_t *b, pthread_mutex_t *c, int num);
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

bool	ft_mutex_unlock(pthread_mutex_t *a, pthread_mutex_t *b, pthread_mutex_t *c, int num)
{
	if (num < 1 || 3 < num)
		return (false);
	if (num >= 1)
		pthread_mutex_unlock(a);
	if (num >= 2)
		pthread_mutex_unlock(b);
	if (num == 3)
		pthread_mutex_unlock(c);
	return (false);
}

bool	print_error(char *str)
{
	printf("%sError\033\n%s", RED, RESET);
	printf("%s%s\n%s", BLUE, str, RESET);
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
	pthread_mutex_destroy(&(*info)->start);
	pthread_mutex_destroy(&(*info)->print);
	pthread_mutex_destroy(&(*info)->check_eat);
	pthread_mutex_destroy(&(*info)->check_end);
	free((*info)->fork);
	free(*info);
	free(*philo);
	*info = 0;
	*philo = 0;
	return (error);
}

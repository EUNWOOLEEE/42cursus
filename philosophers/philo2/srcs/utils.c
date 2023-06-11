/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:15:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/06/09 15:28:26 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(char *str);
bool	ft_mutex_unlock(t_philo *philo, t_info *info, char *mode);
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

bool	ft_mutex_unlock(t_philo *philo, t_info *info, char *mode)
{
	if (mode[0] == '1')
		pthread_mutex_unlock(&info->print);
	if (mode[1] == '1')
		pthread_mutex_unlock(&info->fork[philo->first].mutex);
	if (mode[2] == '1')
		pthread_mutex_unlock(&info->fork[philo->second].mutex);
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

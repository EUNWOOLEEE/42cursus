/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:15:57 by eunwolee          #+#    #+#             */
/*   Updated: 2023/05/26 09:00:55 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void		print_usage();
bool		print_state(t_philo *philo, t_info *info, char *str);
void		*ft_calloc(size_t count, size_t size);
uint64_t	ft_atoi(char *str, bool *state);

void	print_usage()
{
	printf("usage: ./philo number_of_philosophers\n");
	printf("        time_to_die time_to_eat time_to_sleep\n");
	printf("        [number_of_times_each_philosopher_must_eat]\n");
}

bool	print_state(t_philo *philo, t_info *info, char *str)
{
	uint64_t	cur;
	
	if (pthread_mutex_lock(&info->print))
		return (false);
	if(get_time(&cur) == false)
		return (false);
	printf("%llu %d %s\n", cur, philo->philo_id + 1, str);
	if (pthread_mutex_unlock(&info->print))
		return (false);
	return (true);
}

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
	uint64_t res;
	
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		*state = false;
	else
	{
		*state = true;
		while (*str >= '0' && *str <= '9')
			res = (res * 10) + (*str++ - '0');
	}
	return (res);
}
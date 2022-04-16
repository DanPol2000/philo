/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:29:17 by chorse            #+#    #+#             */
/*   Updated: 2022/04/16 16:37:28 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*live(void *arg)
{
	t_philo	*args;

	args = arg;
	args->time_start = ft_time();
	args->start_eat = args->time_start;
	while (1)
	{
		eating(args);
		sleeping(args);
		thinking(args);
		if (args->number_of_times != -1)
			args->number_of_times--;
	}
	return (NULL);
}

static void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork_m);
	pthread_mutex_lock(philo->print);
	printf("%lld %d has taken a fork\n", \
	ft_time() - philo->time_start, philo->id);
	pthread_mutex_unlock(philo->print);
	
}

static void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_m);
	pthread_mutex_lock(philo->print);
	printf("%lld %d has taken a fork\n", \
	ft_time() - philo->time_start, philo->id);
	pthread_mutex_unlock(philo->print);
}

void	eating(t_philo *philo)
{
	if (philo->id % 2)
	{
		take_left_fork(philo);
		take_right_fork(philo);
	}
	else
	{
		take_right_fork(philo);
		take_left_fork(philo);
	}
	pthread_mutex_lock(philo->time);
	philo->start_eat = ft_time();
	pthread_mutex_unlock(philo->time);
	pthread_mutex_lock(philo->print);
	printf("%lld %d is eating\n", \
	philo->start_eat - philo->time_start, philo->id);
	pthread_mutex_unlock(philo->print);
	ft_sleep(philo->time_eat);
	pthread_mutex_unlock(philo->left_fork_m);
	pthread_mutex_unlock(philo->right_fork_m);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d is thinking\n", ft_time() - philo->time_start, philo->id);
	pthread_mutex_unlock(philo->print);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d is sleeping\n", ft_time() - philo->time_start, philo->id);
	pthread_mutex_unlock(philo->print);
	ft_sleep(philo->time_sleep);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:21:35 by chorse            #+#    #+#             */
/*   Updated: 2022/04/17 12:26:36 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	time_of_finish(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(philo->time);
	time = ft_time();
	pthread_mutex_unlock(philo->time);
	if (time - philo->start_eat > philo->time_die)
	{
		if (philo->time_start == 0 && time % 1000 < philo->time_die)
			return (0);
		return (time);
	}
	return (0);
}

static void	kill_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number)
	{
		pthread_detach(data->thread[i]);
		i++;
	}
}

static void	destroy_mt(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(data->print);
	pthread_mutex_destroy(data->time);
	free(data->philo);
	free(data->forks);
	free(data->time);
	free(data->print);
	free(data->thread);
}

void	*moni(void *arg)
{
	int i;
	long time;
	t_data	*data;

	i = 0;
	data = arg;
	usleep(3000);
	while (1)
	{
		if (data->philo[i].number_of_times == 0)
		{
			kill_philo(data);
			destroy_mt(data);
			break ;
		}
		time = time_of_finish(&data->philo[i]);
		if (time > 0)
		{
			pthread_mutex_lock(data->print);
			printf("%lld %d died\n", \
			time - data->philo[i].time_start, data->philo[i].id);
			kill_philo(data);
			destroy_mt(data);
			break ;
		}
		i++;
		if (i == data->number)
			i = 0;
	}
	return (NULL);
}


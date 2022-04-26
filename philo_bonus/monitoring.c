/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:33:36 by chorse            #+#    #+#             */
/*   Updated: 2022/04/26 19:57:55 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*moni(void *arg)
{
	t_data *data;

	data = arg;
	usleep(1000);
	while (1)
	{
		if (data->cycles == 0)
			break ;
		if (ft_time() - data->last_meal > data->die_time)
		{
			sem_wait(data->print);
			printf("%lld %d died\n", \
			ft_time() - data->zero_time, data->id + 1);
			exit(1) ;
		}
	}
	return (NULL);
}

void	monitoring(t_data *data)
{
	pthread_t	monitoring;

	pthread_create(&monitoring, NULL, moni, data);
	pthread_detach(monitoring);
}
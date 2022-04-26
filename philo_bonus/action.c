/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:08:12 by ysachiko          #+#    #+#             */
/*   Updated: 2022/04/26 19:31:10 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	take_forks(t_data *data)
{
	sem_wait(data->general);
	sem_wait(data->forks);
	ft_print_msg(data, 'f');
	sem_wait(data->forks);
	ft_print_msg(data, 'f');
	sem_post(data->general);
}

void	ft_action(t_data *data)
{
	while (data->cycles)
	{
		usleep(300);
		take_forks(data);
		eating(data);
		sleeping(data);
		if (data->eat != -1)
			data->cycles--;
		if (data->cycles == 0)
			exit (0);
	}
	exit (0);
}

void	eating(t_data *data)
{
	ft_print_msg(data, 'e');
	ft_sleep(data->eat_time);
	data->last_meal = ft_time();
	sem_post(data->forks);
	sem_post(data->forks);
}

void	sleeping(t_data *data)
{
	ft_print_msg(data, 's');
	ft_sleep(data->sleep_time);
	ft_print_msg(data, 't');
}

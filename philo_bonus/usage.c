/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:26:54 by chorse            #+#    #+#             */
/*   Updated: 2022/04/26 19:26:48 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	size_t		i;
	long long	j;
	short		sign;

	i = 0;
	j = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (j * 10 + (sign * (str[i] - '0')) < j && sign > 0)
			return (-1);
		if (j * 10 + (sign * (str[i] - '0')) > j && sign < 0)
			return (0);
		j = j * 10 + (sign * (str[i] - '0'));
		i++;
	}
	return (j);
}


void	ft_sleep(long long msec)
{
	struct timeval				cur_time;
	unsigned long long			start_time;
	unsigned long long			end_time;
	unsigned long long			comparison;

	end_time = 0;
	start_time = ft_time();
	comparison = start_time + msec;
	usleep(1000 * msec - 2000);
	while (1)
	{
		gettimeofday(&cur_time, NULL);
		end_time = cur_time.tv_sec * 1000 + cur_time.tv_usec / 1000;
		if (end_time >= comparison)
		{
			return ;
		}
		usleep(250);
	}
}

long long	ft_time(void)
{
	struct timeval	tv;
	long long			res;

	gettimeofday(&tv, NULL);
	res = (long)(tv.tv_sec * 1000) + (long)(tv.tv_usec / 1000);
	return (res);
}

void	ft_print_msg(t_data *data, char msg)
{
	sem_wait(data->print);
	if (msg == 's')
		printf("%lld %d is sleeping\n", \
			ft_time() - data->zero_time, data->id + 1);
	else if (msg == 'e')
		printf("%lld %d is eating\n", \
			ft_time() - data->zero_time, data->id + 1);
	else if (msg == 'f')
		printf("%lld %d has taken a fork\n", \
			ft_time() - data->zero_time, data->id + 1);
	else if (msg == 't')
		printf("%lld %d is thinking\n", \
			ft_time() - data->zero_time, data->id + 1);
	sem_post(data->print);
}

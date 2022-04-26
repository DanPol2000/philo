/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:48:41 by chorse            #+#    #+#             */
/*   Updated: 2022/04/22 17:43:28 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				num;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				left;
	int				right;
	pthread_mutex_t	*left_fork_m;
	pthread_mutex_t	*right_fork_m;
	pthread_mutex_t	*print;
	long long		last_time_eat;
	pthread_mutex_t	*time;
	pthread_mutex_t	*num_times;
	long long		time_start;
	long long		start_eat;
	int				cycles;
	int				must_eat;
	int				id;
}	t_philo;

typedef struct s_data
{
	int				number;
	int				cycles;
	int				eat;
	int				end;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*time;
	pthread_t		*thread;
	pthread_mutex_t	*print;
	pthread_mutex_t	*num_times;
}	t_data;

long	ft_time(void);
int		ft_init_data(int argc, char **argv, t_data *table);
void	ft_init_philo(t_philo *philo, t_data *data, char **argv, int i);
int		ft_atoi(const char *str);
int		ft_init_mut(t_data *data);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	ft_sleep(long long msec);
void	*live(void *arg);
void	*moni(void *arg);
void	red_button(t_data *data, int i, long time);
void	*circle(void *arg);
 long	ft_check_num(t_data *data);
 void	ft_define_cycles_numb(t_data *data);
 
#endif
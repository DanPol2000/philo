/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:56:40 by chorse      #+#    #+#             */
/*   Updated: 2022/04/23 12:17:10 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h> 
# include <signal.h>
# include <semaphore.h>

# define TAKE_FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 3

typedef struct s_data
{
	int				number;
	int				id;
	sem_t			*print;
	sem_t			*forks;
	sem_t			*general;
	int				*children_pids;
	long long		zero_time;
	long long		last_meal;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat;
	int				cycles;
}				t_data;


int	ft_init_data(int argc, char **argv, t_data *data);
int	ft_init_sem(t_data *data);
long	ft_time(void);
void	ft_sleep(long long msec);
int	ft_atoi(const char *str);
int	ft_init_philo(char **argv, t_data *data);
void	ft_define_cycles_numb(t_data *data);

#endif

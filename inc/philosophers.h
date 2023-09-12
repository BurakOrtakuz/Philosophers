/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:33:21 by bortakuz          #+#    #+#             */
/*   Updated: 2023/09/12 15:04:19 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
#include <stdio.h>

typedef struct s_philosophers
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				eat_time;
	int				*total_eat;
	int				remain_death_time;
	int				sleep_time;
	int				plate_times;
	int				is_dead;
	int				death_time;
	uint64_t		*start;
}	t_philosophers;

typedef struct s_data
{
	pthread_t		*threads;
	pthread_t		death_monitor;
	pthread_mutex_t	*forks;
	int				number_of_philo;
	int				total_eat_number;
	int				total_plate;
	uint64_t		start;
	t_philosophers	*all_philos;
	pthread_mutex_t total;
	pthread_mutex_t number;
}	t_data;

void		print_error(char *massage);
void		exit_philo(t_data *data);

int			ft_atoi(const char *str);

void		checker(int ac, char **av);
void		set_all_argumants(t_data *data, char **av);

int			ft_usleep(useconds_t time);
u_int64_t	get_time(void);

void		*eat(void *new_data);
void		*monitor(void *new_data);
#endif
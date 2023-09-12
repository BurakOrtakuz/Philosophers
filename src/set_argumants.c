/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_argumants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:28:02 by bortakuz          #+#    #+#             */
/*   Updated: 2023/09/12 15:04:42 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	set_threads(t_data *data)
{
	int	i;

	data->threads = (pthread_t *)malloc(sizeof(pthread_t)
		* data->number_of_philo);
	pthread_create(&data->death_monitor, NULL, monitor, data);
	i = -1;
	while (i++, i < data->number_of_philo)
	{
		pthread_create(&data->threads[i], NULL, eat, 
			(void *)(&data->all_philos[i]));
	}
	pthread_join(data->death_monitor, NULL);
	i = -1;
	while (i++, i < data->number_of_philo)
	{
		pthread_join(data->threads[i], NULL);
	}
	i = -1;
	while (i++, i < data->number_of_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
	}
}

static void	set_forks(t_data *data)
{
	int	i;

	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->number_of_philo);
	pthread_mutex_init(&data->total, NULL);
	pthread_mutex_init(&data->number, NULL);
	i = -1;
	while (++i, i< 5)
	{
		pthread_mutex_init(&data->forks[i],NULL);
	}
	i = -1;
	while (i++, i < data->number_of_philo)
	{
		data->all_philos[i].left_fork = &data->forks[(i + 1) % data->number_of_philo];
		data->all_philos[i].right_fork = &data->forks[i];
	}
}

static void	set_basic_data(t_data *data, char **av)
{
	int	i;
	int	temp_eat_time;
	int	temp_sleep_time;
	int	temp_total_eat;
	int	temp_death_time;

	i = 0;
	data->number_of_philo = ft_atoi(av[1]);
	temp_death_time = ft_atoi(av[2]);
	temp_eat_time = ft_atoi(av[3]);
	temp_sleep_time = ft_atoi(av[4]);
	if (av[5])
		temp_total_eat = ft_atoi(av[5]);
	else
		temp_total_eat = -1;
	data->total_plate = temp_total_eat;
	data->total_eat_number = 0;
	data->start = 0;
	data->all_philos = (t_philosophers *)malloc(sizeof(t_philosophers) * data->number_of_philo);
	while(i < data->number_of_philo)
	{
		data->all_philos[i].id = i;
		data->all_philos[i].eat_time = temp_eat_time;
		data->all_philos[i].sleep_time = temp_sleep_time;
		data->all_philos[i].plate_times = 0;
		data->all_philos[i].remain_death_time = temp_death_time;
		data->all_philos[i].death_time = temp_death_time;
		data->all_philos[i].is_dead = 0;
		data->all_philos[i].total_eat = &data->total_eat_number;
		data->all_philos[i].start = &data->start;
		i++;
	}
}

void	set_all_argumants(t_data *data, char **av)
{
	set_basic_data(data, av);
	set_forks(data);
	set_threads(data);
}

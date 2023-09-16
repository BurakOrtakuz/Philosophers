/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:55:05 by bortakuz          #+#    #+#             */
/*   Updated: 2023/09/16 18:46:00 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"
#include <stdio.h>

void	*monitor(void *new_data)
{
	t_philosophers	*philo;
	t_philosophers	**philo_temp;
	t_data			*data;
	int				i;
	int				stop;

	philo_temp = (t_philosophers **)(new_data);
	philo = *philo_temp;
	data = philo[0].data;
	data->start = get_time() - 1;
	while (1)
	{
		i = -1;
		stop = 1;
		while (i++, i < data->number_of_philo)
		{
			philo[i].remain_death_time--;
			if (data->total_eaten_meal == -1 || (data->total_eaten_meal
					/ data->number_of_philo) < data->total_meal)
				stop = 0;
			if (philo[i].remain_death_time <= 0)
			{
				printf("%llu %d philo dead\n", get_time() - data->start, i + 1);
				i = -1;
				while (i++, i < data->number_of_philo)
				{
					philo[i].is_dead = 1;
				}
				exit(0);
			}
		}
		if (stop == 1)
		{
			i = -1;
			while (i++, i < data->number_of_philo)
			{
				philo[i].is_dead = 1;
			}
			exit(0);
		}
		ft_usleep(1);
	}
}

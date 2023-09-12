/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:55:05 by bortakuz          #+#    #+#             */
/*   Updated: 2023/09/12 15:53:49 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"
#include <stdio.h>

void	*monitor(void *new_data)
{
	t_data	*data;
	int		i;
	int		stop;

	data = (t_data *)new_data;
	data->start = get_time() - 1;
	while (1)
	{
		i = -1;
		stop = 1;
		while (i++, i < data->number_of_philo)
		{
			data->all_philos[i].remain_death_time--;
			if(data->total_plate == -1 || (data->total_eat_number / data->number_of_philo) < data->total_plate)
				stop = 0;
			if(data->all_philos[i].remain_death_time <= 0)
			{
				printf("%lu %d philo dead\n", get_time() - data->start, i + 1);			
				i = -1;
				while (i++, i< data->number_of_philo)
				{
					data->all_philos[i].is_dead = 1;
				}
				exit(0);
			}
		}
		if(stop == 1)
		{
			i = -1;
			while (i++, i< data->number_of_philo)
			{
				data->all_philos[i].is_dead = 1;
			}
			exit(0);
		}
			
		ft_usleep(1);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:28:02 by bortakuz          #+#    #+#             */
/*   Updated: 2023/09/12 15:55:30 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"
#include <stdio.h>

void	*eat(void *new_data)
{
	t_philosophers *data = (t_philosophers *)(new_data);
	
	if(data->id == data->number_of_philo || data->id == 1)
		ft_usleep(2);
	while (data->is_dead == 0)
	{
		if(((*(data->total_eat)) / data->number_of_philo) == data->plate_times)
		{
			pthread_mutex_lock(data->right_fork);
			printf("%lu %d has taken a fork\n",get_time() - *(data->start), data->id + 1);
			if(pthread_mutex_lock(data->left_fork) == 0)
			{
				printf("%lu %d has taken a fork\n",get_time() - *(data->start), data->id + 1);
				(*(data->total_eat))++;
				data->plate_times++;
				printf("%lu %d is eating\n",get_time() - *(data->start), data->id +1);
				data->remain_death_time = data->death_time;
				ft_usleep(data->eat_time);
				pthread_mutex_unlock(data->right_fork);
				pthread_mutex_unlock(data->left_fork);
				printf("%lu %d is sleping\n",get_time() - *data->start, data->id +1);
				ft_usleep(data->sleep_time);
			}
			else
			{
				pthread_mutex_unlock(data->right_fork);
			}
		}
		else
		{
			//printf("%lu %d is thinking\n",get_time() - *(data->start), data->id +1);
			ft_usleep(1);
		}
	}
	return NULL;
}
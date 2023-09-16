/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:28:02 by bortakuz          #+#    #+#             */
/*   Updated: 2023/09/16 18:42:07 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"
#include <stdio.h>

static void	eat_meal(t_philosophers *data)
{
	printf("%llu %d has taken a fork\n",
		get_time() - data->data->start, data->id + 1);
	data->data->total_eaten_meal++;
	data->eaten_meal++;
	printf("%llu %d is eating\n", get_time() - data->data->start, data->id +1);
	data->remain_death_time = data->data->death_time;
	ft_usleep(data->data->eat_time);
	pthread_mutex_unlock(data->right_fork);
	pthread_mutex_unlock(data->left_fork);
	printf("%llu %d is sleping\n", get_time() - data->data->start, data->id +1);
	ft_usleep(data->data->sleep_time);
	printf("%llu %d is thinking\n", get_time()
		- data->data->start, data->id +1);
}

void	*eat(void *new_data)
{
	t_philosophers	*data;

	data = (t_philosophers *)(new_data);
	if (data->id % 2 == 1)
		ft_usleep(1);
	while (data->is_dead == 0)
	{
		if (((data->eaten_meal) / data->data->number_of_philo)
			== data->data->total_eaten_meal)
		{
			pthread_mutex_lock(data->right_fork);
			printf("%llu %d has taken a fork\n",
				get_time() - data->data->start, data->id + 1);
			if (pthread_mutex_lock(data->left_fork) == 0)
				eat_meal(data);
			else
				pthread_mutex_unlock(data->right_fork);
		}
		else
		{
			ft_usleep(1);
		}
	}
	return (NULL);
}

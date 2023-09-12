/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:32:41 by bortakuz          #+#    #+#             */
/*   Updated: 2023/09/12 14:08:05 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_data			data;

	checker(ac, av);
	set_all_argumants(&data, av);
	return (0);
}

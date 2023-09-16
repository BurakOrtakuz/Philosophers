/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:32:41 by bortakuz          #+#    #+#             */
/*   Updated: 2023/09/16 18:43:25 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_philosophers	*data;

	data = NULL;
	checker(ac, av);
	set_all_argumants(data, av);
	return (0);
}

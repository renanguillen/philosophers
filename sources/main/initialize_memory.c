/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:27:55 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/10 16:04:30 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Initialize the memory of the program using the arguments.
* Uses the gettimeofday() function to get the start time.

* Returns a pointer to the allocated memory.
*/
t_data	*initialize_memory(int argc, char **argv)
{
	t_data			*memory;
	struct timeval	time;

	memory = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!memory)
		return (NULL);
	memory->philo_count = ft_atoi(argv[1]);
	memory->time_to_die = ft_atoi(argv[2]);
	memory->time_to_eat = ft_atoi(argv[3]);
	memory->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		memory->eat_count = ft_atoi(argv[5]);
	else
		memory->eat_count = -1;
	memory->forks = (pthread_mutex_t *)ft_calloc(memory->philo_count,
			sizeof(pthread_mutex_t));
	if (!memory->forks)
		return (NULL);
	memory->philosophers = (t_philosopher *)ft_calloc(memory->philo_count,
			sizeof(t_philosopher));
	if (!memory->philosophers)
		return (NULL);
	memory->start_time = gettimeofday(&time, NULL);
	return (memory);
}

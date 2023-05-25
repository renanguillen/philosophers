/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:52:54 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/25 15:52:14 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Destroys every mutex created by the program: fork locks, meal locks,
* the write and simulation stopper lock.

* Returns nothing.
*/
static void	wash_the_dishes(t_simulation *simulation)
{
	unsigned int	i;

	i = 0;
	while (i < simulation->nb_philos)
	{
		pthread_mutex_destroy(&simulation->fork_locks[i]);
		pthread_mutex_destroy(&simulation->philos[i]->meal_time_lock);
		i++;
	}
	pthread_mutex_destroy(&simulation->write_lock);
	pthread_mutex_destroy(&simulation->sim_stop_lock);
	return ;
}

/*
* Stops the simulation by joining all the threads and destroying the mutexes.
* Then, frees the memory allocated for the simulation.

* Returns the exit code.
*/
int	stop_simulation(t_simulation *simulation)
{
	unsigned int	i;

	i = 0;
	while (i < simulation->nb_philos)
	{
		pthread_join(simulation->philos[i]->thread, NULL);
		i++;
	}
	if (simulation->nb_philos > 1)
		pthread_join(simulation->observer, NULL);
	wash_the_dishes(simulation);
	return (exit_handler(simulation, NULL, 0));
}

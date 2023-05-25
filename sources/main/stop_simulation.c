/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:52:54 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/25 16:18:31 by ridalgo-         ###   ########.fr       */
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
	while (i < simulation->how_many)
	{
		pthread_mutex_destroy(&simulation->fork_mutexes[i]);
		pthread_mutex_destroy(&simulation->philos[i]->meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&simulation->write_mutex);
	pthread_mutex_destroy(&simulation->stop_mutex);
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
	while (i < simulation->how_many)
	{
		pthread_join(simulation->philos[i]->thread, NULL);
		i++;
	}
	if (simulation->how_many > 1)
		pthread_join(simulation->observer, NULL);
	wash_the_dishes(simulation);
	return (exit_handler(simulation, NULL, 0));
}

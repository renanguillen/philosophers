/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:48:15 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/25 16:18:31 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Makes the philosopher think, sleep and eat until the simulation is over.

* Returns nothing.
*/
static void	eat_sleep_think(t_philosopher *philosopher)
{
	action_eat(philosopher);
	action_sleep(philosopher);
	action_think(philosopher, YES);
	return ;
}

/*
* Since a lone philosopher only has one fork, he will never be able to eat.
* This makes it wait for its time to die and then die.
* #sad

* Returns sadness.
*/
static void	*lonely(t_philosopher *plato)
{
	pthread_mutex_lock(&plato->simulation->fork_mutexes[plato->fork[0]]);
	print_status(plato, NO, FORK);
	action_wait(plato->simulation, plato->simulation->time_to_die);
	print_status(plato, NO, DEAD);
	pthread_mutex_unlock(&plato->simulation->fork_mutexes[plato->fork[0]]);
	return (NULL);
}

/*
* Makes the philosopher think, sleep and eat until the simulation is over. If
* the philosopher's ID is odd, he will think before eating for the first time,
* asserting that the philosophers will not all try to eat at the same time,
* avoiding deadlocks. If the philosopher's ID is even, he will eat before
* thinking for the first time. This function also handles a lone philosopher,
* which will never be able to eat.

* Returns NULL.
*/
void	*philosopher_routine(void *argument)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)argument;
	if (philosopher->simulation->must_eat_count == 0)
		return (NULL);
	pthread_mutex_lock(&philosopher->meal_mutex);
	philosopher->last_meal = philosopher->simulation->start_time;
	pthread_mutex_unlock(&philosopher->meal_mutex);
	allign_start_times(philosopher->simulation->start_time);
	if (philosopher->simulation->time_to_die == 0)
		return (NULL);
	if (philosopher->simulation->how_many == 1)
		return (lonely(philosopher));
	else if (philosopher->id % 2)
		action_think(philosopher, NO);
	while (is_it_over(philosopher->simulation) == NO)
		eat_sleep_think(philosopher);
	return (NULL);
}

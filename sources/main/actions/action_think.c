/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_think.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:24:43 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/23 13:41:07 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

/*
* Calculates the time a philosopher will think for, depending on how long
* it has been since his last meal, the time_to_eat and the time_to_die.
* This helps stagger philosopher's eating routines to avoid forks being
* monopolized by one philosopher.
* If the time_to_think is greater than 600ms, it is capped at 200ms. This is
* to avoid the philosopher thinking for too long and starving to death.

* Returns the time the philosopher will think for.
*/
static time_t	set_time_to_think(t_philosopher *philosopher)
{
	time_t	time_to_think;

	pthread_mutex_lock(&philosopher->meal_time_lock);
	time_to_think = (philosopher->simulation->time_to_die
			- (ft_fetch_time() - philosopher->last_meal)
			- philosopher->simulation->time_to_eat) / 2;
	pthread_mutex_unlock(&philosopher->meal_time_lock);
	if (time_to_think <= 0)
		time_to_think = 1;
	if (time_to_think > 600)
		time_to_think = 200;
	return (time_to_think);
}

/*
* Simulates a philosopher "thinking" by printing the status and waiting for
* the calculated amount of time.

* Returns nothing.
*/
void	action_think(t_philosopher *philosopher, int should_print)
{
	time_t	time_to_think;

	time_to_think = set_time_to_think(philosopher);
	if (should_print == YES)
		print_status(philosopher, NO, THINKING);
	action_wait(philosopher->simulation, time_to_think);
	return ;
}

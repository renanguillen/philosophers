/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:35:03 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/22 21:45:22 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Simulates the philosopher taking a nap after eating. Unlocks the forks,
* then the philosopher "sleeps" for the specified time.

* Returns nothing.
*/
void	action_sleep(t_philosopher *philo)
{
	print_status(philo, NO, SLEEPING);
	pthread_mutex_unlock(&philo->simulation->fork_locks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->simulation->fork_locks[philo->fork[0]]);
	action_wait(philo->simulation, philo->simulation->time_to_sleep);
	return ;
}

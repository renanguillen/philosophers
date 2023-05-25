/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:18:27 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/25 16:18:31 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

/*
* Simulates the philosopher eating. Locks the forks, updates the last meal
* time, then the philosopher "eats" for the specified time.

* Returns nothing.
*/
void	action_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->simulation->fork_mutexes[philo->fork[0]]);
	print_status(philo, NO, FORK);
	pthread_mutex_lock(&philo->simulation->fork_mutexes[philo->fork[1]]);
	print_status(philo, NO, FORK);
	print_status(philo, NO, EATING);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = ft_fetch_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	action_wait(philo->simulation, philo->simulation->time_to_eat);
	if (is_it_over(philo->simulation) == NO)
	{
		pthread_mutex_lock(&philo->meal_mutex);
		philo->eaten += 1;
		pthread_mutex_unlock(&philo->meal_mutex);
	}
	return ;
}

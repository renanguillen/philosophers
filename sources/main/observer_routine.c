/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:58 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/25 16:18:02 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Switches the simulation stop flag to the specified value.

* Returns nothing.
*/
static void	keep_going_with_this(t_simulation *simulation, int check)
{
	pthread_mutex_lock(&simulation->stop_mutex);
	if (check == YES)
		simulation->stop_flag = NO;
	else
		simulation->stop_flag = YES;
	pthread_mutex_unlock(&simulation->stop_mutex);
	return ;
}

/*
* Checks if the philosopher has died. If so, flags the simulation to stop.

* Returns YES if the philosopher has died, NO otherwise.
*/
static int	someone_died(t_philosopher *philo)
{
	time_t	time;

	time = ft_fetch_time();
	if ((time - philo->last_meal) >= philo->simulation->time_to_die)
	{
		keep_going_with_this(philo->simulation, NO);
		print_status(philo, YES, DEAD);
		pthread_mutex_unlock(&philo->meal_mutex);
		return (YES);
	}
	return (NO);
}

/*
* Checks if either the conditions for the simulation to stop are met.
* If the simulation has a must_eat_count, checks if all philosophers have
* eaten enough.
* If the simulation has a time_to_die, checks if any philosopher has died.

* Returns YES if the simulation must stop, NO otherwise.
*/
static int	had_enough_of_this(t_simulation *simulation)
{
	unsigned int	i;
	int				enough;

	enough = YES;
	i = 0;
	while (i < simulation->how_many)
	{
		pthread_mutex_lock(&simulation->philos[i]->meal_mutex);
		if (someone_died(simulation->philos[i]))
			return (YES);
		if (simulation->must_eat_count != -1)
			if (simulation->philos[i]->eaten
				< (unsigned int)simulation->must_eat_count)
				enough = NO;
		pthread_mutex_unlock(&simulation->philos[i]->meal_mutex);
		i++;
	}
	if (simulation->must_eat_count != -1 && enough == YES)
	{
		keep_going_with_this(simulation, NO);
		return (YES);
	}
	return (NO);
}

/*
* The observer routine. It checks if the philosophers are still alive and
* if they have eaten enough.
* Flags the simulation to stop if needed.

* Returns nothing.
*/
void	*observer_routine(void *argument)
{
	t_simulation	*simulation;

	simulation = (t_simulation *)argument;
	if (simulation->must_eat_count == 0)
		return (NULL);
	keep_going_with_this(simulation, YES);
	allign_start_times(simulation->start_time);
	while (YES)
	{
		if (had_enough_of_this(simulation) == YES)
			return (NULL);
		usleep(50);
	}
	return (NULL);
}

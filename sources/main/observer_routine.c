/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:07:58 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/23 13:35:13 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static void	keep_going_with_this(t_simulation *simulation, int check)
{
	pthread_mutex_lock(&simulation->sim_stop_lock);
	if (check == YES)
		simulation->sim_stop = NO;
	else
		simulation->sim_stop = YES;
	pthread_mutex_unlock(&simulation->sim_stop_lock);
}

static int	someone_died(t_philosopher *philo)
{
	time_t	time;

	time = ft_fetch_time();
	if ((time - philo->last_meal) >= philo->simulation->time_to_die)
	{
		keep_going_with_this(philo->simulation, YES);
		print_status(philo, YES, DEAD);
		pthread_mutex_unlock(&philo->meal_time_lock);
		return (YES);
	}
	return (NO);
}

static int	had_enough_of_this(t_simulation *simulation)
{
	unsigned int	i;
	int				enough;

	enough = YES;
	i = 0;
	while (i < simulation->nb_philos)
	{
		pthread_mutex_lock(&simulation->philos[i]->meal_time_lock);
		if (someone_died(simulation->philos[i]))
			return (YES);
		if (simulation->must_eat_count != -1)
			if (simulation->philos[i]->times_ate
				< (unsigned int)simulation->must_eat_count)
				enough = NO;
		pthread_mutex_unlock(&simulation->philos[i]->meal_time_lock);
		i++;
	}
	if (simulation->must_eat_count != -1 && enough == YES)
	{
		keep_going_with_this(simulation, YES);
		return (YES);
	}
	return (NO);
}

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
		usleep(1000);
	}
	return (NULL);
}

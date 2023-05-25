/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:48:36 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/25 16:16:46 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Assigns each philosopher as right or left handed depending on their id to 
* avoid deadlocks.

* Returns nothing.
*/
static void	assign_forks(t_philosopher *philo)
{
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->simulation->how_many;
		philo->fork[1] = philo->id;
	}
	else
	{
		philo->fork[0] = philo->id;
		philo->fork[1] = (philo->id + 1) % philo->simulation->how_many;
	}
	return ;
}

/*
* Initialize the philosophers. Allocates memory for each philosopher and
* initializes their mutexes.

* Returns 0 if successful, 1 if not.
*/
static int	init_philosophers(t_simulation *simulation)
{
	unsigned int	i;

	i = 0;
	while (i < simulation->how_many)
	{
		simulation->philos[i] = (t_philosopher *)ft_calloc
			(1, sizeof(t_philosopher));
		if (!simulation->philos[i])
			return (exit_handler(simulation, MSG_MEMORY, ERR_MEMORY));
		if (pthread_mutex_init(&simulation->philos[i]->meal_mutex, NULL))
			return (exit_handler(simulation, MSG_MTX_INIT, ERR_MTX_INIT));
		simulation->philos[i]->simulation = simulation;
		simulation->philos[i]->id = i;
		assign_forks(simulation->philos[i]);
		i++;
	}
	return (CONTROL_OK);
}

/*
* Initialize the table containing all the philosophers and their forks.
* Allocates memory for each philosopher and their forks.

* Returns 0 if successful, 1 if not.
*/
int	init_table(t_simulation *simulation)
{
	simulation->philos = (t_philosopher **)ft_calloc(simulation->how_many,
			sizeof(t_philosopher *));
	if (!simulation->philos)
		return (exit_handler(simulation, MSG_MEMORY, ERR_MEMORY));
	return (init_philosophers(simulation));
}

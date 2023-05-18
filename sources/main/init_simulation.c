/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:27:55 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/17 23:22:42 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static int	init_philosophers(t_simulation *simulation)
{
	unsigned int	i;

	simulation->philos = (t_philosopher **)ft_calloc(simulation->nb_philos,
			sizeof(t_philosopher *));
	if (!simulation->philos)
		return (exit_handler(simulation, "philo: allocation failed", 2));
	i = 0;
	while (i < simulation->nb_philos)
	{
		simulation->philos[i] = (t_philosopher *)ft_calloc
			(1, sizeof(t_philosopher));
		if (!simulation->philos[i])
			return (exit_handler(simulation, "philo: allocation failed", 2));
		if (pthread_mutex_init(&simulation->philos[i]->meal_time_lock, 0))
			return (exit_handler(simulation, "philo: mutex init failed", 4));
		simulation->philos[i]->simulation = simulation;
		simulation->philos[i]->id = i;
		//IM HERE
		// assign_forks(simulation->philos[i]);
		i++;
	}
	return (0);
}

void	print_simulation(t_simulation *simulation)
{
	unsigned int i;

	i = 0;
	printf("Simulation:\n");
	printf("Number of philosophers: %d\n", simulation->nb_philos);
	printf("Time to die: %ld\n", simulation->time_to_die);
	printf("Time to eat: %ld\n", simulation->time_to_eat);
	printf("Time to sleep: %ld\n", simulation->time_to_sleep);
	printf("Must eat count: %d\n", simulation->must_eat_count);
	while (i < simulation->nb_philos)
		printf("Philosopher %d:\n", simulation->philos[i++]->id);
}

/*
* Initialize the memory of the program using the arguments.

* Returns a pointer to the allocated memory.
*/
t_simulation	*init_simulation(int argc, char **argv)
{
	t_simulation	*simulation;

	simulation = (t_simulation *)ft_calloc(1, sizeof(t_simulation));
	if (!simulation)
		return (NULL);
	simulation->nb_philos = ft_atoi(argv[1]);
	simulation->time_to_die = ft_atoi(argv[2]);
	simulation->time_to_eat = ft_atoi(argv[3]);
	simulation->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		simulation->must_eat_count = ft_atoi(argv[5]);
	else
		simulation->must_eat_count = -1;
	if (init_philosophers(simulation))
		return (NULL);
	// if (init_forks(simulation))
		// return (NULL);
	print_simulation(simulation);
	return (simulation);
}

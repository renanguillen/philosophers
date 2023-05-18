/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:27:55 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/18 15:39:33 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Initializes the mutexes used to control the simulation.

* Returns 0 or the exit code.
*/
static int	init_locks(t_simulation *simulation)
{
	if (pthread_mutex_init(&simulation->sim_stop_lock, NULL))
		return (exit_handler(simulation, MSG_MTX_INIT, ERR_MTX_INIT));
	if (pthread_mutex_init(&simulation->write_lock, NULL))
		return (exit_handler(simulation, MSG_MTX_INIT, ERR_MTX_INIT));
	return (CONTROL_OK);
}

/*
* Initializes the forks' mutexes used to control the simulation.

* Returns 0 or the exit code.
*/
static int	init_forks(t_simulation *simulation)
{
	unsigned int	i;

	simulation->fork_locks = (pthread_mutex_t *)
		ft_calloc(simulation->nb_philos, sizeof(pthread_mutex_t));
	if (!simulation->fork_locks)
		return (exit_handler(simulation, MSG_MEMORY, ERR_MEMORY));
	i = 0;
	while (i < simulation->nb_philos)
	{
		if (pthread_mutex_init(&simulation->fork_locks[i], NULL))
			return (exit_handler(simulation, MSG_MTX_INIT, ERR_MTX_INIT));
		i++;
	}
	return (CONTROL_OK);
}

/*
* Sets the simulation parameters passed as arguments via the command line.

* Returns 0.
*/
static int	init_parameters(t_simulation *simulation, int argc, char **argv)
{
	simulation->nb_philos = ft_atoi(argv[1]);
	simulation->time_to_die = ft_atoi(argv[2]);
	simulation->time_to_eat = ft_atoi(argv[3]);
	simulation->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		simulation->must_eat_count = ft_atoi(argv[5]);
	else
		simulation->must_eat_count = -1;
	return (CONTROL_OK);
}

/*
* Initialize the memory of the program using the arguments.
* All philosophers are initialized and their forks are assigned.

* Returns 0 if successful or the exit code if not.
*/
int	init_simulation(t_simulation *simulation, int argc, char **argv)
{
	int	control;

	control = init_parameters(simulation, argc, argv);
	control = init_table(simulation);
	if (control)
		return (control);
	control = init_forks(simulation);
	if (control)
		return (control);
	control = init_locks(simulation);
	if (control)
		return (control);
	return (CONTROL_OK);
}

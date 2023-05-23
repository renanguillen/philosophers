/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:25:31 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/23 18:52:36 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
*	Destroys every mutex created by the program: fork locks, meal locks,
*	the write and simulation stopper lock.
*/
static void	destroy_mutexes(t_simulation *simulation)
{
	unsigned int	i;

	i = 0;
	while (i < simulation->nb_philos)
	{
		pthread_mutex_destroy(&simulation->fork_locks[i]);
		pthread_mutex_destroy(&simulation->philos[i]->meal_time_lock);
		i++;
	}
	pthread_mutex_destroy(&simulation->write_lock);
	pthread_mutex_destroy(&simulation->sim_stop_lock);
}

/*
* Takes the red pill and get ready to wake up in the real world.
* Free the memory allocated for the simulation.

* Returns nothing.
*/
static void	red_pill(t_simulation *simulation)
{
	if (simulation)
		destroy_mutexes(simulation);
	if (simulation->fork_locks)
		ft_free_pointer((void **)&simulation->fork_locks);
	if (simulation->philos)
		ft_free_ppointer((void ***)&simulation->philos);
	ft_free_pointer((void **)&simulation);
	return ;
}

/*
* Prints the error message and frees the memory allocated for the simulation.

* Returns the exit code.
*/
int	exit_handler(t_simulation *simulation, char *print_this, int exit_code)
{
	if (print_this)
		printf("%s\n", print_this);
	if (simulation)
		red_pill(simulation);
	return (exit_code);
}

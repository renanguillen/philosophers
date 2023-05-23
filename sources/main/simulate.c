/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:05:40 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/18 19:09:30 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Simulates the philosophers' actions by creating a thread for each
* philosopher and one for the observer.

* Returns 0 if the simulation was successfully started or the exit code
* if there was an error creating the threads.
*/
int	simulate(t_simulation *simulation)
{
	unsigned int	i;

	simulation->start_time = ft_fetch_time();
	i = 0;
	while (i < simulation->nb_philos)
	{
		if (pthread_create(&simulation->philos[i]->thread, NULL,
				&philosopher_routine, simulation->philos[i]))
			return (exit_handler(simulation, MSG_TRD_INIT, ERR_TRD_INIT));
		i++;
	}
	if (simulation->nb_philos > 1)
	{
		if (pthread_create(&simulation->observer, NULL,
				&observer_routine, simulation))
			return (exit_handler(simulation, MSG_TRD_INIT, ERR_TRD_INIT));
	}
	return (CONTROL_OK);
}

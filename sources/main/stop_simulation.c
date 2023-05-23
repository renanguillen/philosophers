/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:52:54 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/23 18:54:54 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	stop_simulation(t_simulation *simulation)
{
	unsigned int	i;

	i = 0;
	while (i < simulation->nb_philos)
	{
		pthread_join(simulation->philos[i]->thread, NULL);
		i++;
	}
	if (simulation->nb_philos > 1)
		pthread_join(simulation->observer, NULL);
	return (exit_handler(simulation, NULL, 0));
}

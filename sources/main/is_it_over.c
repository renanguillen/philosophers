/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_over.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:51:50 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/25 16:18:02 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Checks if the simulation is running or not, by protecting the
* simulation stop flag with a mutex lock.

* Returns 1 if the simulation is over, 0 if it is still running.
*/
int	is_it_over(t_simulation *simulation)
{
	int	control;

	control = NO;
	pthread_mutex_lock(&simulation->stop_mutex);
	if (simulation->stop_flag == YES)
		control = YES;
	pthread_mutex_unlock(&simulation->stop_mutex);
	return (control);
}

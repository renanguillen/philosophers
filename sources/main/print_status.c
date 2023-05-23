/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:03:09 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/22 21:49:18 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Prints the philosopher's status as required by the subject.

* Returns nothing.
*/
static void	formatted_print(t_philosopher *philo, char *status)
{
	printf("%ld %d %s\n", ft_fetch_time() - philo->simulation->start_time,
		philo->id + 1, status);
	return ;
}

void	print_status(t_philosopher *philosopher, int observer, int status)
{
	pthread_mutex_lock(&philosopher->simulation->write_lock);
	if (is_it_over(philosopher->simulation) == YES && observer == NO)
	{
		pthread_mutex_unlock(&philosopher->simulation->write_lock);
		return ;
	}
	if (status == DEAD)
		formatted_print(philosopher, "died");
	else if (status == EATING)
		formatted_print(philosopher, "is eating");
	else if (status == SLEEPING)
		formatted_print(philosopher, "is sleeping");
	else if (status == THINKING)
		formatted_print(philosopher, "is thinking");
	else if (status == FORK)
		formatted_print(philosopher, "has taken a fork");
	pthread_mutex_unlock(&philosopher->simulation->write_lock);
}

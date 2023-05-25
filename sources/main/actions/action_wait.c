/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_wait.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:31:30 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/25 18:51:03 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/philosophers.h"

/*
* Waits for the specified time. Checking for the simulation status every 100
* microseconds.

* Returns nothing.
*/
void	pretend_to_do_something(time_t ftaot, t_simulation *simulation)
{
	while (ft_fetch_time() < ftaot)
	{
		if (is_it_over(simulation))
			break ;
		usleep(100);
	}
	return ;
}

/*
* Simulates an action being done for the specified time.

* Returns nothing.
*/
void	action_wait(t_simulation *simulation, time_t wait_time)
{
	time_t	for_this_amount_of_time;

	for_this_amount_of_time = ft_fetch_time() + wait_time;
	pretend_to_do_something(for_this_amount_of_time, simulation);
	return ;
}

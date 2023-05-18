/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:25:31 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/17 22:59:49 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Takes the red pill and get ready to wake up in the real world.
* Free the memory allocated for the simulation.

* Returns nothing.
*/
static void	red_pill(t_simulation *simulation)
{
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
int	exit_handler(t_simulation *simulation, char *error_to_print, int exit_code)
{
	if (error_to_print)
		printf("%s\n", error_to_print);
	if (simulation)
		red_pill(simulation);
	return (exit_code);
}

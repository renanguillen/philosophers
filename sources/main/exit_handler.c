/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:25:31 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/25 16:18:31 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

// /*
// * Takes the red pill and get ready to wake up in the real world.
// * Free the memory allocated for the simulation.

// * Returns nothing.
// */
static void	red_pill(t_simulation *simulation)
{
	unsigned int	i;

	if (!simulation)
		return ;
	if (simulation->fork_mutexes != NULL)
		free(simulation->fork_mutexes);
	if (simulation->philos != NULL)
	{
		i = 0;
		while (i < simulation->how_many)
		{
			if (simulation->philos[i] != NULL)
				free(simulation->philos[i]);
			i++;
		}
		free(simulation->philos);
	}
	free(simulation);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:17:03 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/23 19:10:55 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Main function of the program.
* Executes the simulation and prints the results.

* Returns the exit code after deallocating the memory.
*/
int	main(int argc, char **argv)
{
	t_simulation	*simulation;
	int				control;

	if (check_arguments(argc, argv))
		return (ERR_ARGS);
	simulation = (t_simulation *)ft_calloc(1, sizeof(t_simulation));
	if (!simulation)
		return (ERR_MEMORY);
	control = init_simulation(simulation, argc, argv);
	if (control)
		return (control);
	control = simulate(simulation);
	if (control)
		return (control);
	control = stop_simulation(simulation);
	if (control)
		return (control);
	return (CONTROL_OK);
}

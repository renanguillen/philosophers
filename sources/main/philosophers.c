/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:17:03 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/18 15:47:47 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void print_simulation(t_simulation *simulation)
{
	printf("Number of philosophers: %d\n", simulation->nb_philos);
	printf("Time to die: %ld\n", simulation->time_to_die);
	printf("Time to eat: %ld\n", simulation->time_to_eat);
	printf("Time to sleep: %ld\n", simulation->time_to_sleep);
	printf("Number of times each philosopher must eat: %d\n", simulation->must_eat_count);
	for (unsigned int i = 0; i < simulation->nb_philos; i++)
	{
		printf("Philosopher %d:\n", simulation->philos[i]->id);
		printf("  fork_left: %d\n", simulation->philos[i]->fork[0]);
		printf("  fork_right: %d\n", simulation->philos[i]->fork[1]);
	}
	return ;
}

/*
* Main function of the program.

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
	print_simulation(simulation);
	return (CONTROL_OK);
}

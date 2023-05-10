/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:29:02 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/10 16:14:39 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Print the error message according to the exit code.

* Returns the exit code.
*/
static int	print_argument_error(int exit_code)
{
	if (exit_code == ERR_ARG_COUNT)
		printf("Error(%d): Wrong number of arguments.\n", exit_code);
	else if (exit_code == ERR_PHILO_COUNT)
		printf("Error(%d): There must be at least 1 philosopher.\n", exit_code);
	else if (exit_code == ERR_TTD)
		printf("Error(%d): Time to die must be positive\n", exit_code);
	else if (exit_code == ERR_TTE)
		printf("Error(%d): Time to eat must be positive\n", exit_code);
	else if (exit_code == ERR_TTS)
		printf("Error(%d): Time to sleep must be positive\n", exit_code);
	else if (exit_code == ERR_EAT_COUNT)
		printf("Error(%d): They must eat at least once.\n", exit_code);
	return (exit_code);
}

/*
* Check if the arguments are valid.

* Returns the exit code.
*/
int	check_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (print_argument_error(ERR_ARG_COUNT));
	else if (ft_atoi(argv[1]) < 1)
		return (print_argument_error(ERR_PHILO_COUNT));
	else if (ft_atoi(argv[2]) <= 0)
		return (print_argument_error(ERR_TTD));
	else if (ft_atoi(argv[3]) <= 0)
		return (print_argument_error(ERR_TTE));
	else if (ft_atoi(argv[4]) <= 0)
		return (print_argument_error(ERR_TTS));
	else if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (print_argument_error(ERR_EAT_COUNT));
	return (CHECK_OK);
}

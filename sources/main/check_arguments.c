/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:29:02 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/17 23:07:37 by ridalgo-         ###   ########.fr       */
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
		printf("Error(1-%d): Wrong number of arguments.\n", exit_code);
	else if (exit_code == ERR_PHILO_COUNT)
		printf("Error(1-%d): Philosophers should range from 2-250\n", exit_code);
	else if (exit_code == ERR_TTD)
		printf("Error(1-%d): Time to die must be a positive int\n", exit_code);
	else if (exit_code == ERR_TTE)
		printf("Error(1-%d): Time to eat must be a positive int\n", exit_code);
	else if (exit_code == ERR_TTS)
		printf("Error(1-%d): Time to sleep must be a positive int\n", exit_code);
	else if (exit_code == ERR_EAT_COUNT)
		printf("Error(1-%d): Philosophers must eat at least once.\n", exit_code);
	return (ERR_ARGS);
}

/*
* Check if the arguments are valid.

* Returns the exit code.
*/
int	check_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (print_argument_error(ERR_ARG_COUNT));
	else if (ft_onlydigits(argv[1]) || ft_atoi(argv[1]) < 2
		|| ft_atoi(argv[1]) > PHI_MAX)
		return (print_argument_error(ERR_PHILO_COUNT));
	else if (ft_onlydigits(argv[2]) || ft_atoi(argv[2]) <= 0)
		return (print_argument_error(ERR_TTD));
	else if (ft_onlydigits(argv[3]) || ft_atoi(argv[3]) <= 0)
		return (print_argument_error(ERR_TTE));
	else if (ft_onlydigits(argv[4]) || ft_atoi(argv[4]) <= 0)
		return (print_argument_error(ERR_TTS));
	else if (argc == 6 && (ft_onlydigits(argv[5]) || ft_atoi(argv[5]) < 1))
		return (print_argument_error(ERR_EAT_COUNT));
	return (CHECK_OK);
}

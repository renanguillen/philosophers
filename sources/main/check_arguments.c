/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:29:02 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/18 15:34:42 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Check if the arguments are valid. If not, print the error message.

* Returns 0 if the arguments are valid, a positive int otherwise.
*/
int	check_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (printf("Error(1): Wrong number of arguments.\n"));
	else if (ft_onlydigits(argv[1]) || ft_atoi(argv[1]) < 2
		|| ft_atoi(argv[1]) > PHI_MAX)
		return (printf("Error(1): Philosophers should range from 2-250\n"));
	else if (ft_onlydigits(argv[2]) || ft_atoi(argv[2]) <= 0)
		return (printf("Error(1): Time to die must be a positive int\n"));
	else if (ft_onlydigits(argv[3]) || ft_atoi(argv[3]) <= 0)
		return (printf("Error(1): Time to eat must be a positive int\n"));
	else if (ft_onlydigits(argv[4]) || ft_atoi(argv[4]) <= 0)
		return (printf("Error(1): Time to sleep must be a positive int\n"));
	else if (argc == 6 && (ft_onlydigits(argv[5]) || ft_atoi(argv[5]) < 1))
		return (printf("Error(1): Philosophers must eat at least once.\n"));
	return (CONTROL_OK);
}

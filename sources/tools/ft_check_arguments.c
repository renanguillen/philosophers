/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:29:02 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/03 17:18:29 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Check if the arguments are valid.

* Returns CHECK_OK if the arguments are valid, otherwise returns ERROR_ARGUMENT.
*/
int	ft_check_arguments(int argc, char **argv)
{
	int	exit_code;

	exit_code = CHECK_OK;
	if (argc < 5 || argc > 6)
		exit_code = ERROR_ARGUMENT;
	else if (ft_atoi(argv[1]) < 2)
		exit_code = ERROR_ARGUMENT;
	else if (ft_atoi(argv[2]) <= 0)
		exit_code = ERROR_ARGUMENT;
	else if (ft_atoi(argv[3]) <= 0)
		exit_code = ERROR_ARGUMENT;
	else if (ft_atoi(argv[4]) <= 0)
		exit_code = ERROR_ARGUMENT;
	else if (argc == 6 && ft_atoi(argv[5]) < 1)
		exit_code = ERROR_ARGUMENT;
	return (exit_code);
}

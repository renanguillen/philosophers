/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:17:03 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/10 16:04:02 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Main function of the program.

* Returns the exit code after deallocating the memory.
*/
int	main(int argc, char **argv)
{
	int		exit_code;
	t_data	*memory;

	exit_code = check_arguments(argc, argv);
	if (exit_code)
		return (exit_code);
	memory = initialize_memory(argc, argv);
	return (deallocate_memory(memory));
}

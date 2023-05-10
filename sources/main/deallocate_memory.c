/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocate_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:24:52 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/10 16:04:44 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Deallocates the memory used by the program.

* Returns the exit code.
*/
int	deallocate_memory(t_data *memory)
{
	int	exit_code;

	exit_code = memory->exit_code;
	ft_free_pointer((void **)&memory->forks);
	ft_free_pointer((void **)&memory->philosophers);
	ft_free_pointer((void **)&memory);
	return (exit_code);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:27:14 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/03 17:09:44 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Print the error message according to the exit_code.
*/
void	ft_print_error(int exit_code)
{
	if (exit_code == ERROR_ARGUMENT)
		printf("Please check your arguments.\n");
	else
		return ;
}

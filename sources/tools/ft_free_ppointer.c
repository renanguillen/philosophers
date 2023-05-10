/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ppointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:05:16 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/10 15:58:51 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Frees a pointer to pointer and set it to NULL.

* Returns nothing.
*/
void	ft_free_ppointer(void ***ppointer)
{
	int	index;

	index = 0;
	if (!*ppointer)
		return ;
	while ((*ppointer)[index])
	{
		ft_free_pointer((void **)&((*ppointer)[index]));
		(*ppointer)[index] = NULL;
		index++;
	}
	ft_free_pointer((void **)ppointer);
	*ppointer = NULL;
	return ;
}

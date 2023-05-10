/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:58:57 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/10 15:58:55 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Frees a pointer and set it to NULL.

* Returns nothing.
*/
void	ft_free_pointer(void **pointer)
{
	if (!*pointer)
		return ;
	free(*pointer);
	*pointer = NULL;
	return ;
}

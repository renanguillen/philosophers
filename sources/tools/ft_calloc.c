/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:46:53 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/10 15:58:27 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Allocates memory for an array of num_elements elements of element_size bytes
* each.

* The memory blocks are set to zero. If num_elements or element_size is 0, then
* returns NULL

* Returns a pointer to the allocated memory, or NULL if the request fails.
*/
void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*block;
	size_t	index;

	block = malloc(num_elements * element_size);
	if (!block)
		return (NULL);
	index = 0;
	while (index < num_elements * element_size)
	{
		((char *)block)[index] = 0;
		index++;
	}
	return (block);
}

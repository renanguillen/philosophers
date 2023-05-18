/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlydigits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:09:04 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/15 15:21:26 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Checks if the string contains only digits.

* Returns 0 if true, 1 if false.
*/
int	ft_onlydigits(char *value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if (value[i] < '0' || value[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

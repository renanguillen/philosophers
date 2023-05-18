/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:01:35 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/15 15:20:23 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Converts the string to an integer.

* Returns the converted value.
*/
int	ft_atoi(const char *string)
{
	unsigned long long int	nb;
	int						i;

	i = 0;
	nb = 0;
	while (string[i] && (string[i] >= '0' && string[i] <= '9'))
	{
		nb = nb * 10 + (string[i] - '0');
		i++;
	}
	if (nb > INT_MAX)
		return (-1);
	return ((int)nb);
}

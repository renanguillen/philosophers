/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:01:35 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/03 17:09:17 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Converts the initial portion of the string pointed to by _string to int.
*/
int	ft_atoi(const char *string)
{
	int	neg;
	int	result;
	int	index;

	neg = 1;
	index = 0;
	while (string[index] == 32 || (string[index] >= 9 && string[index] <= 13))
		index++;
	if (string[index] == '+' || string[index] == '-')
	{
		if (string[index] == '-')
			neg = -1;
		index++;
	}
	result = 0;
	while (string[index] >= '0' && string[index] <= '9')
	{
		result = result * 10;
		result = result + (string[index] - 48);
		index++;
	}
	return (result * neg);
}

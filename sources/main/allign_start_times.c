/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allign_start_times.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:23:24 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/05/19 16:21:01 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/*
* Wait for all threads to start simultaniouslly.

* Returns nothing
*/
void	allign_start_times(time_t start_time)
{
	while (ft_fetch_time() < start_time)
		continue ;
}

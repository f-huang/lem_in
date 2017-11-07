/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:37:52 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/07 21:40:36 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tube	*tube_find(t_tube *tubes, t_room *needle1, t_room *needle2)
{
	t_tube	*iterator;

	iterator = tubes;
	while (iterator)
	{
		if ((iterator->gate1 == needle1 && iterator->gate2 == needle2) ||\
			(iterator->gate1 == needle2 && iterator->gate2 == needle1))
			return (iterator);
		iterator = iterator->next;
	}
	return (NULL);
}

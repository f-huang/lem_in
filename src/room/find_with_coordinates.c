/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_with_coordinates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:35:42 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/05 15:39:18 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

t_room	*room_find_with_coordinates(t_room *rooms, int x, int y)
{
	t_room	*iterator;

	iterator = rooms;
	while (iterator)
	{
		if (iterator->x == x && iterator-> y == y)
			return (iterator);
		iterator = iterator->next;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_destination.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:54:23 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/11 19:15:18 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"

static void	attach_room(t_room **room, t_room *gate)
{
	if (!(*room)->destinations)
	{
		(*room)->destinations = gate;
	}
	else
	{
		gate->next_destination = (*room)->destinations;
		(*room)->destinations = gate;
	}
}

void	room_add_destination(t_room **rooms, t_room *gate1, t_room *gate2)
{
	t_room	*room;

	if (!gate1 || !gate2 || !*rooms)
		return ;
	room = room_find(*rooms, gate1->name);
	if (!room)
		return ;
	attach_room(&room, gate2);
	printf("Attach %s to %s\n", gate2->name, gate1->name);
	room = room_find(*rooms, gate2->name);
	if (!room)
		return ;
	attach_room(&room, gate1);
	printf("Attach %s to %s\n", gate1->name, gate2->name);
}

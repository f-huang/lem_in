/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:48:17 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/04 18:49:10 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

t_room	*room_find(t_room *rooms, const char *name)
{
	t_room	*iterator;

	if (!name || ft_isstrempty(name))
		return (0);
	iterator = rooms;
	while (iterator)
	{
		if (ft_strequ(iterator->name, name))
			return (iterator);
		iterator = iterator->next;
	}
	return (NULL);
}

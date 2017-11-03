/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:24:11 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/03 18:36:18 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	room_delete_all(t_room **rooms)
{
	t_room	*iterator;
	t_room	*previous;

	previous = NULL;
	iterator = *rooms;
	while (iterator)
	{
		previous = iterator;
		iterator = iterator->next;
		ft_strdel(&previous->name);
		ft_memdel((void**)&previous);
	}
}

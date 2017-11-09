/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:17:05 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/09 16:16:38 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	room_add(t_room **rooms, size_t *size, const char *name, int x, int y)
{
	t_room	*new;

	if (!name)
		return ;
	new = (t_room*)ft_memalloc(sizeof(t_room));
	new->name = ft_strdup(name);
	new->x = x;
	new->y = y;
	if (!*rooms)
		*rooms = new;
	else
	{
		new->next = *rooms;
		*rooms = new;
	}
	(*size)++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tube.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:20:50 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/04 18:50:06 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int		is_tube(t_game *game, const char *line)
{
	char	**tab;
	t_room	*gate1;
	t_room	*gate2;
	int		len;

	if (!(tab = ft_strsplit(line, TUBE_SEPARATOR)))
		return (0);
	if ((len = ft_tablen(tab) < 2))
	{
		ft_tabfree(&tab);
		return (0);
	}
	else if (len == 2)
	{
		if (!(gate1 = room_find(game->rooms, tab[0]))\
			|| !(gate2 = room_find(game->rooms, tab[1])))
			return (0);
		tube_add(&game->tubes, gate1, gate2);
	}
	else
	{
		// Find names with '-'
			// not found
				// return error
			// found
				// check if corresponds
					// yes
						// create tube
					// no
						// return error
	}
	ft_tabfree(&tab);
	return (1);
}

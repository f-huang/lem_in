/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tube.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:20:50 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/05 19:25:44 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

static void	find_corresponding_rooms(t_room *rooms, char **tab, int len)
{
	t_room	*room;
	char	*potential_name;
	int		i;

	room = rooms;
	i = 0;
	while (i + 1 < len)
	{
		potential_name = ft_str3join(tab[i], STRINGIFY_MACRO_VALUE(TUBE_SEPARATOR), tab[i + 1]);
		room = room_find(rooms, potential_name);
		ft_strdel(&potential_name);
		if (room)
			break ;
		++i;
	}
}

int		is_tube(t_game *game, const char *line)
{
	char	**tab;
	t_room	*gate1;
	t_room	*gate2;
	int		len;

	if (!(tab = ft_strsplit(line, TUBE_SEPARATOR)))
		return (0);
	if ((len = ft_tablen(tab)) < 2)
	{
		ft_tabfree(&tab);
		return (0);
	}
	else if (len == 2)
	{
		if (!(gate1 = room_find(game->rooms, tab[0]))\
			|| !(gate2 = room_find(game->rooms, tab[1])) || gate1 == gate2)
			return (0);
		tube_add(&game->tubes, gate1, gate2);
	}
	else
	{
		find_corresponding_rooms(game->rooms, tab, len);
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

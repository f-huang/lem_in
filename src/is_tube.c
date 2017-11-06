/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tube.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:20:50 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/06 19:15:53 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

static void	find_corresponding_rooms(t_room *rooms, const char *line)
{
	const char	pattern[2]
	t_room	*room;
	char	*tmp;

	pattern[0] = TUBE_SEPARATOR;
	pattern[1] = 0;
	room = rooms;
	ft_putendlcol(STRINGIFY_MACRO_VALUE(TUBE_SEPARATOR), GREEN);
	tmp = ft_strstr(line, STRINGIFY_MACRO_VALUE(TUBE_SEPARATOR));
	if (tmp)
		ft_putendlcol(tmp, RED);
	else
		ft_putendlcol("(null)", RED);

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
		find_corresponding_rooms(game->rooms, line);
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

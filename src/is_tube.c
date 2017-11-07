/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tube.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:20:50 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/07 21:52:27 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

static int	find_corresponding_rooms(t_room *rooms, const char *line, t_room **gate1, t_room **gate2)
{
	static const char	pattern[2] = {TUBE_SEPARATOR, 0};
	char				*part1;
	char				*part2;

	part2 = (char*)line;
	while ((part2 = ft_strstr(part2, pattern)) && *part2)
	{
		if (!(part1 = ft_strndup(line, (size_t)(part2 - line))))
			return (0);
		part2 += 1;
		*gate1 = room_find(rooms, part1);
		*gate2 = room_find(rooms, part2);
		ft_strdel(&part1);
		if (*gate1 && *gate2)
			return (1);
	}
	return (0);
}

int			is_tube(t_game *game, const char *line)
{
	t_room				*gate1;
	t_room				*gate2;

	gate1 = NULL;
	gate2 = NULL;
	if (!ft_strfind_c(line, TUBE_SEPARATOR))
		return (0);
	if ((find_corresponding_rooms(game->rooms, line, &gate1, &gate2)))
	{
		if (tube_find(game->tubes, gate1, gate2))
			return (0);
		tube_add(&game->tubes, gate1, gate2);
	}
	return (gate1 && gate2);
}

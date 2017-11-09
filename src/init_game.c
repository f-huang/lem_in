/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:37:57 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/09 16:54:10 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

static int	init_ants(t_game *game)
{
	size_t	i;

	game->ants = (t_ant*)ft_memalloc(sizeof(t_ant) * game->nb_ants);
	if (!game->ants)
		return (0);
	i = 0;
	while (i < game->nb_ants)
	{
		game->ants[i] = (t_ant) {
			.position = game->entry,
			.can_play = 0
		};
		++i;
	}
	return (1);
}

int			init_game(t_game *game)
{
	char	*line;
	int		ret;

	line = NULL;
	while ((ret = read_stdin(&line)))
	{
		if (ret == -1 || !line || ft_isstrempty(line) || !handle_line(game, line))
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!init_ants(game))
		return (0);
	return (1);
}

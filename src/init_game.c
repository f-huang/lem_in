/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:37:57 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/11 19:20:13 by fhuang           ###   ########.fr       */
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
			.has_played = 0,
			.coming_from = NULL
		};
		++i;
	}
	return (1);
}

static void	print(t_game *game)
{
	t_room	*iterator;
	t_room	*destination;

	iterator = game->rooms;
	while (iterator)
	{
		ft_printf("^CYAN^[%s]^EOC^\n", iterator->name);
		destination = iterator->destinations;
		while (destination)
		{
			ft_printf("\t• %s\n", destination->name);
			destination = destination->next_destination;
		}
		iterator = iterator->next;
	}
}

int			init_game(t_game *game)
{
	char	*line;
	int		ret;

	line = NULL;
	while ((ret = read_stdin(&line)))
	{
		if (ret == -1 || !line)
			return (0);
		else if (ft_isstrempty(line))
			break ;
		else if (!handle_line(game, line))
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!init_ants(game))
		return (0);
	print(game);
	return (1);
}

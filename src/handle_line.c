/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:46:34 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/09 16:54:34 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

static int	should_command_be_here(t_game game)
{
	if (game.next_action & ACTION_START)
		return (game.nb_ants != 0 && !game.entry);
	if (game.next_action & ACTION_END)
		return (game.nb_ants != 0 && !game.exit);
	return (1);
}

static int	set_entry_exit(t_game *game)
{
	if (game->next_action & ACTION_START)
	{
		if (game->entry != NULL)
			return (0);
		game->entry = game->rooms;
		game->next_action ^= ACTION_START;
	}
	else if (game->next_action & ACTION_END)
	{
		if (game->exit != NULL)
			return (0);
		game->exit = game->rooms;
		game->next_action ^= ACTION_END;
	}
	return (1);
}


int		handle_line(t_game *game, const char *line)
{
	int		ret;
	char	*trimmed;

	if (is_comment(line))
		return (1);
	else if (is_command(&game->next_action, line))
		return (should_command_be_here(*game));
	if (!(trimmed = ft_strtrim(line)))
		return (0);
	if (game->nb_ants == 0)
		return (read_nb_ants(game, trimmed));
	else
	{
		ret = 1;
		if (!game->tubes && (ret = is_room(game, trimmed)))
			return (!ret ? 0 : set_entry_exit(game));
		else
		{
			if (!ret && (game->next_action & ACTION_START || game->next_action & ACTION_END))
				return (0);
			else if (game->rooms && game->entry && game->exit && is_tube(game, trimmed))
				return (1);
			return (0);
		}
	}
}

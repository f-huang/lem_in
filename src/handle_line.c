/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:46:34 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/04 21:24:20 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

#include <stdio.h>

static int	should_command_be_here(t_game game)
{
	if (game.next_action & ACTION_START)
		return (game.nb_ants != 0 && !game.entry);
	if (game.next_action & ACTION_END)
		return (game.nb_ants != 0 && !game.exit);
	return (1);
}

int		handle_line(t_game *game, const char *line)
{
	int		ret;

	if (is_comment(line))
	{
		ft_putendlcol("comment", YELLOW);
		return (1);
	}
	if (is_command(&game->next_action, line))
	{
		ret = should_command_be_here(*game);
		ft_printf("^YELLOW^command : %s\n^EOC^", ret ? "should be here" : "should not be here");
		return (ret);
	}
	if (game->nb_ants == 0)
	{
		ft_putendlcol("nb_ants", YELLOW);
		return (read_nb_ants(game, line));
	}
	if (!game->tubes)
	{
		if (!game->nb_ants)
			return (0);
		if ((ret = is_room(game, line)))
		{
			ft_putendlcol("room", YELLOW);
			return (ret == -1 ? 0 : set_entry_exit(game));
		}
		else
		{
			if (game->next_action & ACTION_START || game->next_action & ACTION_END)
				return (0);
			return (is_tube(game, line));
		}
		//is room
			// yes
				// is start || end
					// desactivate flag
					// if already set
						//return 0
					// set entry || exit
				// return 1
			// no
				// is flag start || end set
					// yes
						// return 0
					// no
						//check if tube
							// yes return 1
							// no return 0
	}
	return (is_tube(game, line));
	//return is tube
	return (1);
}

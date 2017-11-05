/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_entry_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:58:07 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/04 18:06:13 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		set_entry_exit(t_game *game)
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

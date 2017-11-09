/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:35:42 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/09 16:42:03 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

void	clear_game(t_game *game)
{
	room_delete_all(&game->rooms);
	tube_delete_all(&game->tubes);
	if (game->ants)
		ft_memdel((void**)&game->ants);
	ft_bzero(game, sizeof(t_game));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_game_ready.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:00:32 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/09 16:22:12 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_game_ready(t_game game)
{
	return (
		game.nb_ants > 0 &&\
		game.entry && game.exit &&\
		game.entry != game.exit &&\
		game.nb_tubes > 0 &&\
		game.nb_rooms > 1
	);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:48:34 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/09 16:54:08 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

static int	error_encountered(t_game *game)
{
	clear_game(game);
	ft_putendl_fd(LEM_IN_ERROR, 2);
	return (1);
}

int		main(void)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (!init_game(&game) || !is_game_ready(game))
		return (error_encountered(&game));
	//Launch game
	return (0);
}

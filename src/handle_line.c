/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:46:34 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/03 19:12:27 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		handle_line(t_game *game, const char *line)
{
	static int	((*f[])(t_game *, const char*)) = {
		[READ_NB_ANTS] = read_nb_ants
	};

	if (is_comment(line))
		return (1);
	return (f[game->step](game, line));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:48:34 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/03 19:09:44 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int		main(void)
{
	t_game	game;
	char	*line;
	int		ret;

	ft_bzero(&game, sizeof(t_game));
	game.step = READ_NB_ANTS;
	line = NULL;
	while ((ret = read_stdin(&line)))
	{
		if (ret == -1)
			break ;
		if (!line || ft_isstrempty(line) || !handle_line(&game, line))
			break ;
		ft_strdel(&line);
	}
	if (line)
		ft_strdel(&line);
	//Launch game
	return (0);
}

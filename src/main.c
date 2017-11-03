/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:48:34 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/03 18:23:45 by fhuang           ###   ########.fr       */
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
	line = NULL;
	while ((ret = read_stdin(&line)))
	{
		if (ret == -1)
			break ;
		ft_strdel(&line);
	}
	if (line)
		ft_strdel(&line);
	return (0);
}
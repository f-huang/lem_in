/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_nb_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:52:21 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/07 22:44:49 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int		read_nb_ants(t_game *game, const char *line)
{
	int		nb;

	if (!ft_isstrdigit(line) || !ft_isint(line))
		return (0);
	nb = ft_atoi(line);
	if (nb < 1)
		return (0);
	game->nb_ants = (size_t)nb;
	return (1);
}

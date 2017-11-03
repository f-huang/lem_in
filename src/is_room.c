/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:15:13 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/03 19:33:26 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

static char	*get_room_name(char **tab, int tablen)
{
	char	*name;
	char	*tmp;
	int		i;

	name = ft_strnew(0);
	i = 0;
	while (name && i + 1 < tablen - 2)
	{
		tmp = name;
		name = ft_strjoin(tab[i], tab[i + 1]);
		ft_strdel(&tmp);
		++i;
	}
	return (name);
}

static void	create_room(t_game *game, char **tab, int len)
{
	char	*name;
	int		x;
	int		y;

	x = ft_atoi(tab[len - 2]);
	y = ft_atoi(tab[len - 1]);
	len = 0;
	name = get_room_name(tab, len);
	room_add(&game->rooms, name, x , y);
}

int		is_room(t_game *game, const char *line)
{
	char	**tab;
	int		len;

	if (!(tab = ft_strsplit(line, ROOM_SEPARATOR)))
		return (0);
	if ((len = ft_tablen(tab)) < 3\
		|| !ft_isstrdigit(tab[len - 1]) || !ft_isstrdigit(tab[len - 2])\
		|| !ft_isint(tab[len - 1]) || !ft_isint(tab[len - 2]))
	{
		ft_tabfree(&tab);
		return (0);
	}
	create_room(game, tab, len);
	ft_tabfree(&tab);
	return (1);
}

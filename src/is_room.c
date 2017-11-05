/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:15:13 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/05 15:55:16 by fhuang           ###   ########.fr       */
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
		name = ft_str3join(tab[i], " ", tab[i + 1]);
		ft_strdel(&tmp);
		++i;
	}
	return (name);
}

static int	is_room_unique(t_room *rooms, const char *name, int x, int y)
{
	t_room	*tmp;

	tmp = room_find(rooms, name);
	if (tmp != NULL)
		return (0);
	tmp = room_find_with_coordinates(rooms, x, y);
	return (tmp == NULL);
}

static int	create_room(t_game *game, char **tab, int len)
{
	char	*name;
	int		x;
	int		y;
	int		ret;

	x = ft_atoi(tab[len - 2]);
	y = ft_atoi(tab[len - 1]);
	if (len > 3)
		name = get_room_name(tab, len);
	else
		name = ft_strdup(tab[0]);
	if ((ret = is_room_unique(game->rooms, name, x, y)))
		room_add(&game->rooms, name, x , y);
	ft_strdel(&name);
	return (ret);
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
	len = create_room(game, tab, len);
	ft_tabfree(&tab);
	return (len);
}

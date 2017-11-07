/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:10:42 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/07 22:44:17 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int		is_command(int *action, const char *line)
{
	enum e_game_command	command;
	char				*str;
	int					ret;

	if (!ft_strnequ(line, PREFIX_COMMAND, ft_strlen(PREFIX_COMMAND)))
		return (0);
	ret = 1;
	str = ft_strtrim((char*)line + ft_strlen(PREFIX_COMMAND));
	if (str)
	{
		if (((int)(command = get_command_enum(str)) != -1))
		{
			if (command == START)
				*action |= ACTION_START;
			else if (command == END)
				*action |= ACTION_END;
		}
		else if (ft_isstrempty(str))
			ret = 0;
		ft_strdel(&str);
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_enum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:04:34 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/04 15:10:26 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

enum e_game_command	get_command_enum(const char *str)
{
	int		i;

	i = 0;
	while (i < NB_COMMANDS)
	{
		if (ft_strequ(str, get_command_name(i)))
			return (i);
		++i;
	}
	return (-1);
}

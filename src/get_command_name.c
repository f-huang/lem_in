/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:06:35 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/04 15:08:37 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

const char	*get_command_name(enum e_game_command command)
{
	static const char	*names[] = {
		[START] = COMMAND_START,
		[END] = COMMAND_END
	};

	return (names[command]);
}

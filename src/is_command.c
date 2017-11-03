/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:10:42 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/03 19:13:18 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int		is_command(const char *line)
{
	return (ft_strnequ(line, PREFIX_COMMAND, ft_strlen(PREFIX_COMMAND)));
}

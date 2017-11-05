/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:08:21 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/04 17:46:54 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int		is_comment(const char *line)
{
	return (ft_strnequ(line, PREFIX_COMMENT, ft_strlen(PREFIX_COMMENT))\
		&& line[1] != '#');
}

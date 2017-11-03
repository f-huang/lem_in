/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:36:22 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/03 18:38:46 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	tube_add(t_tube **tubes, t_room *gate1, t_room *gate2)
{
	t_tube	*new;

	if (!gate1 || !gate2)
		return ;
	new = (t_tube*)ft_memalloc(sizeof(t_tube));
	new->gate1 = gate1;
	new->gate2 = gate2;
	if (!*tubes)
		*tubes = new;
	else
	{
		new->next = (*tubes)->next;
		*tubes = new;
	}
}

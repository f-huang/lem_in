/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:36:44 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/03 18:39:08 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	tube_delete_all(t_tube **tubes)
{
	t_tube	*iterator;
	t_tube	*previous;

	previous = NULL;
	iterator = *tubes;
	while (iterator)
	{
		previous = iterator;
		iterator = iterator->next;
		ft_memdel((void**)&previous);
	}
}

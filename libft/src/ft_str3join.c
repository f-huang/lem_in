/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:50:46 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/05 15:52:44 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str3join(char *s1, char *s2, char *s3)
{
	char    *ret;

	if (!s1 || !s2 || !s3)
		return (NULL);
	ret = ft_strndup(s1, ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3));
	if (ret == NULL)
		return (NULL);
	ret = ft_strcat(ret, s2);
	ret = ft_strcat(ret, s3);
	return (ret);
}

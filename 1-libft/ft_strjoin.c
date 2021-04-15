/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:16:56 by anradix           #+#    #+#             */
/*   Updated: 2018/11/17 10:35:24 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (s1 && s2)
	{
		if (!(str = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
			return (NULL);
		ft_strcat(str, s1);
		ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}

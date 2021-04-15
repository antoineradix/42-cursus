/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:18:43 by anradix           #+#    #+#             */
/*   Updated: 2018/11/19 20:17:43 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dup;

	if (!(dup = (char*)malloc(sizeof(*s) * (ft_strlen(s) + 1))))
		return (NULL);
	return (ft_strcpy(dup, s));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 08:05:58 by anradix           #+#    #+#             */
/*   Updated: 2018/11/21 14:07:57 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = src;
	d = dst;
	if (d == s)
		return (dst);
	if (s < d)
		ft_memcpy(d, s, len);
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}

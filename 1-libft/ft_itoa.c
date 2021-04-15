/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:35:49 by anradix           #+#    #+#             */
/*   Updated: 2018/11/16 18:24:02 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		size;
	int		tmp;
	char	*str;

	size = n < 0 ? 2 : 1;
	tmp = n;
	while (tmp /= 10)
		size++;
	if (!(str = ft_strnew(size)))
		return (NULL);
	tmp = n;
	while (size--)
	{
		str[size] = (n < 0 ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	if (tmp < 0)
		str[0] = '-';
	return (str);
}

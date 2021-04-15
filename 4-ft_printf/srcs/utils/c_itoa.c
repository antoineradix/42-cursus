/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_itoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:55:00 by anradix           #+#    #+#             */
/*   Updated: 2019/11/18 18:56:15 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*c_itoa(t_printf *p, uintmax_t nb, size_t len, char c)
{
	static char	s[101];

	s[len] = '\0';
	while (len--)
	{
		s[len] = (nb % p->base < 10) ? nb % p->base + '0'
		: nb % p->base + c - 10;
		nb /= p->base;
	}
	return (s);
}

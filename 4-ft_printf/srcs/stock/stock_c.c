/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:47:02 by anradix           #+#    #+#             */
/*   Updated: 2019/11/19 16:49:30 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	stock_c(t_printf *p, char c)
{
	int	min;

	min = p->min_len ? p->min_len - 1 : 0;
	if (p->flags & MINUS)
	{
		n_buffer(p, c, 1);
		if (min > 0)
			n_buffer(p, ' ', min);
	}
	else
	{
		if (min > 0)
			n_buffer(p, (p->flags & ZERO) ? '0' : ' ', min);
		n_buffer(p, c, 1);
	}
}

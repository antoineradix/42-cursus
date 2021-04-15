/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:40:11 by anradix           #+#    #+#             */
/*   Updated: 2019/11/19 16:44:19 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	stock_p(t_printf *p, uintmax_t nb)
{
	int		len;
	int		min;

	get_base(p);
	len = c_nbrlen(nb, p->base, 0);
	min = p->min_len - 2 - len;
	if (nb == 0 && p->precision == -1)
		stock_hash(p);
	else
	{
		if (p->flags & MINUS)
		{
			stock_hash(p);
			s_buffer(p, c_itoa(p, nb, c_nbrlen(nb, p->base, 0), 'a'), len);
			if (min > 0)
				n_buffer(p, ' ', min);
		}
		else
		{
			if (min > 0)
				n_buffer(p, ' ', min);
			stock_hash(p);
			s_buffer(p, c_itoa(p, nb, c_nbrlen(nb, p->base, 0), 'a'), len);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:47:45 by anradix           #+#    #+#             */
/*   Updated: 2019/11/20 14:03:41 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	stock_o(t_printf *p, uintmax_t nb)
{
	int		len;
	int		min;
	int		prec;

	get_base(p);
	len = c_nbrlen(nb, p->base, 0);
	if ((p->precision == -1 || p->flags & HASH) && nb == 0)
		len = 0;
	prec = check_zero(p, len);
	min = p->min_len ? (p->min_len - prec - len) : 0;
	min -= ((p->flags & HASH) && (len >= p->precision)) ? 1 : 0;
	if (p->flags & MINUS)
	{
		prec = check_hash_o(p, prec);
		u_padding(p, prec, len, nb);
		if (min > 0)
			n_buffer(p, ' ', min);
	}
	else
	{
		if (min > 0)
			n_buffer(p, ' ', min);
		prec = check_hash_o(p, prec);
		u_padding(p, prec, len, nb);
	}
}

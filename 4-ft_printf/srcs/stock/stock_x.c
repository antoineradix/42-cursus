/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:07:46 by anradix           #+#    #+#             */
/*   Updated: 2019/11/19 16:11:32 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	stock_x(t_printf *p, uintmax_t nb)
{
	int		len;
	int		min;
	int		prec;

	get_base(p);
	len = c_nbrlen(nb, p->base, 0);
	len += (*p->frmt == 'p') ? 2 : 0;
	len = (p->precision == -1 && nb == 0) ? 0 : len;
	prec = check_zero(p, len);
	min = p->min_len ? (p->min_len - prec - len) : 0;
	min -= ((p->flags & HASH) && (nb != 0)) ? 2 : 0;
	if (p->flags & MINUS)
	{
		prec = check_hash_x(p, prec, nb);
		u_padding(p, prec, len, nb);
		if (min > 0)
			n_buffer(p, ' ', min);
	}
	else
	{
		if (min > 0)
			n_buffer(p, ' ', min);
		prec = check_hash_x(p, prec, nb);
		u_padding(p, prec, len, nb);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:23:50 by anradix           #+#    #+#             */
/*   Updated: 2019/11/19 16:49:18 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	stock_u(t_printf *p, uintmax_t nb)
{
	int		len;
	int		min;
	int		prec;

	len = c_nbrlen(nb, p->base, 0);
	if (p->precision == -1 && nb == 0)
		len = 0;
	prec = check_zero(p, len);
	min = p->min_len ? (p->min_len - prec - len) : 0;
	if ((p->flags & PLUS) || (p->flags & SPACE) || p->neg)
		min -= 1;
	if (p->flags & MINUS)
	{
		u_padding(p, prec, len, nb);
		if (min > 0)
			n_buffer(p, ' ', min);
	}
	else
	{
		if (min > 0)
			n_buffer(p, ' ', min);
		u_padding(p, prec, len, nb);
	}
}

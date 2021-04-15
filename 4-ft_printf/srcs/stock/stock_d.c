/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:47:04 by anradix           #+#    #+#             */
/*   Updated: 2019/11/18 19:03:04 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	stock_d(t_printf *p, uintmax_t nb)
{
	int		len;
	int		min;
	int		prec;

	len = c_nbrlen(nb, 10, 0);
	if (p->precision == -1 && nb == 0)
		len = 0;
	prec = check_zero(p, len);
	min = p->min_len ? (p->min_len - prec - len) : 0;
	if ((p->flags & PLUS) || (p->flags & SPACE) || p->neg)
		min -= 1;
	if (p->flags & MINUS)
	{
		padding(p, prec, len, nb);
		if (min > 0)
			n_buffer(p, ' ', min);
	}
	else
	{
		if (min > 0)
			n_buffer(p, ' ', min);
		padding(p, prec, len, nb);
	}
}

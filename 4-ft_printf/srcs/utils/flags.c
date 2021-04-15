/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:48:55 by anradix           #+#    #+#             */
/*   Updated: 2019/11/20 17:04:50 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	stock_hash(t_printf *p)
{
	n_buffer(p, '0', 1);
	if (*p->frmt == 'x' || *p->frmt == 'p')
		n_buffer(p, 'x', 1);
	else if (*p->frmt == 'X')
		n_buffer(p, 'X', 1);
}

int		check_hash_x(t_printf *p, int prec, uintmax_t nb)
{
	if ((p->flags & HASH) && nb != 0)
	{
		stock_hash(p);
		prec = p->precision ? prec : prec - 2;
	}
	return (prec);
}

int		check_hash_o(t_printf *p, int prec)
{
	if (p->flags & HASH)
	{
		stock_hash(p);
		prec -= 1;
	}
	return (prec);
}

int		check_plus(t_printf *p, int len, int prec)
{
	if (p->flags & PLUS)
	{
		n_buffer(p, '+', 1);
		if (len >= p->precision)
			prec -= 1;
	}
	return (prec);
}

int		check_zero(t_printf *p, int len)
{
	int prec;

	if (p->flags & ZERO)
	{
		prec = p->precision ? p->precision - len :
			(p->min_len - len - p->neg);
		if ((p->flags & SPACE) && (p->precision == 0))
			prec -= 1;
	}
	else
		prec = p->precision ? p->precision - len : 0;
	prec = prec < 0 ? 0 : prec;
	return (prec);
}

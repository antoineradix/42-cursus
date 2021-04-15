/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:27:53 by anradix           #+#    #+#             */
/*   Updated: 2019/11/19 17:08:20 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	get_unb(t_printf *p)
{
	uintmax_t	nb;

	if (*p->frmt == 'p')
		nb = (uintmax_t)va_arg(p->va, void *);
	else
	{
		nb = (p->flags & L)
		? (uintmax_t)(va_arg(p->va, unsigned long long))
		: (uintmax_t)(va_arg(p->va, unsigned int));
	}
	if (p->flags & H || p->flags & HH)
		nb = (p->flags & HH) ? (unsigned char)nb : (unsigned short)nb;
	return (nb);
}

uintmax_t	get_nb(t_printf *p)
{
	intmax_t	nb;

	nb = (p->flags & L) ? (intmax_t)(va_arg(p->va, long long int))
	: (intmax_t)(va_arg(p->va, int));
	if (p->flags & H || p->flags & HH)
		nb = (p->flags & HH) ? (char)nb : (short)nb;
	if (nb < 0)
	{
		(p->flags &= ~PLUS) && (p->flags &= ~SPACE);
		p->neg = 1;
		nb *= -1;
	}
	return (nb);
}

void		get_type(t_printf *p)
{
	if (*p->frmt == 'd' || *p->frmt == 'i')
		return (stock_d(p, get_nb(p)));
	if (*p->frmt == 'o' || *p->frmt == 'b')
		return (stock_o(p, get_unb(p)));
	if (*p->frmt == 'x' || *p->frmt == 'X')
		return (stock_x(p, get_unb(p)));
	if (*p->frmt == 'u')
		return (stock_u(p, get_unb(p)));
	if (*p->frmt == 'p')
		return (stock_p(p, get_unb(p)));
	if (*p->frmt == 'c' || *p->frmt == 'C' || *p->frmt == '%')
		return (stock_c(p, (*p->frmt == '%') ? '%' : va_arg(p->va, int)));
	if (*p->frmt == 's' || *p->frmt == 'S')
		return (stock_s(p, va_arg(p->va, char*)));
	return (stock_error(p));
}

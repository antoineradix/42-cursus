/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:51:35 by anradix           #+#    #+#             */
/*   Updated: 2019/11/19 16:00:56 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_padding(t_printf *p, int prec, int len, uintmax_t nb)
{
	if (prec > 0)
		n_buffer(p, '0', prec);
	if (*p->frmt == 'X')
		s_buffer(p, c_itoa(p, nb, c_nbrlen(nb, p->base, 0), 'A'), len);
	else
		s_buffer(p, c_itoa(p, nb, c_nbrlen(nb, p->base, 0), 'a'), len);
}

void	padding(t_printf *p, int prec, int len, uintmax_t nb)
{
	prec = check_plus(p, len, prec);
	(p->flags & SPACE) ? n_buffer(p, ' ', 1) : 0;
	p->neg ? n_buffer(p, '-', 1) : 0;
	if (prec > 0)
		n_buffer(p, '0', prec);
	if (*p->frmt == 'X')
		s_buffer(p, c_itoa(p, nb, c_nbrlen(nb, p->base, 0), 'A'), len);
	else
		s_buffer(p, c_itoa(p, nb, c_nbrlen(nb, p->base, 0), 'a'), len);
}

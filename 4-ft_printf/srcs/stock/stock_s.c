/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:51:04 by anradix           #+#    #+#             */
/*   Updated: 2019/11/19 17:01:32 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	stock_s(t_printf *p, char *s)
{
	int		len;
	int		min;

	len = s ? s_len(s, 0, '\0') : 6;
	if (s == NULL)
		s = "(null)";
	if (p->precision && p->precision < len)
		len = (p->precision == -1) ? 0 : p->precision;
	min = p->min_len ? p->min_len - len : 0;
	if (p->flags & MINUS)
	{
		s_buffer(p, s, len);
		if (min > 0)
			n_buffer(p, ' ', min);
	}
	else
	{
		if (min > 0)
			n_buffer(p, (p->flags & ZERO) ? '0' : ' ', min);
		s_buffer(p, s, len);
	}
}

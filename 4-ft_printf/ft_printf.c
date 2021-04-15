/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:52:17 by anradix           #+#    #+#             */
/*   Updated: 2019/11/20 15:57:50 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_printf	p;

	if (!format || BUFF_SIZE < 1)
		return (0);
	init_struct(&p, 0);
	p.frmt = (char *)format;
	va_start(p.va, format);
	while (*p.frmt)
		(*p.frmt == '%') ? parsing(&p) : n_buffer(&p, *p.frmt++, 1);
	write(1, p.buff, p.i);
	return (p.len);
}

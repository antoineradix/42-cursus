/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:27:08 by anradix           #+#    #+#             */
/*   Updated: 2019/11/19 15:45:51 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	go_to_next_flags(t_printf *p)
{
	if (*p->frmt == '*')
		p->frmt++;
	else if (is_digit(*p->frmt))
		while (p->frmt && is_digit(*p->frmt))
			p->frmt++;
}

void	get_width_pr(t_printf *p)
{
	if (is_digit(*p->frmt) || *p->frmt == '*')
	{
		p->min_len = *p->frmt == '*' ? va_arg(p->va, int) : c_atoi(*&p->frmt);
		go_to_next_flags(p);
	}
	if (*p->frmt == '.')
	{
		p->frmt++;
		while (p->frmt && *p->frmt == '0')
			p->frmt++;
		if ((is_digit(*p->frmt) || *p->frmt == '*'))
		{
			p->precision = (*p->frmt == '*')
			? va_arg(p->va, int) : c_atoi(*&p->frmt);
		}
		if (p->precision == 0)
			p->precision = -1;
		go_to_next_flags(p);
	}
}

void	get_flags(t_printf *p)
{
	short	tmp;

	while ((tmp = s_chr(" -+#0", *p->frmt)) > -1 && *p->frmt++)
		p->flags |= (1 << tmp);
	get_width_pr(p);
	while ((tmp = s_chr("lh", *p->frmt)) > -1 && *p->frmt++)
	{
		if (tmp == 1 && p->flags & H)
			p->flags |= HH;
		else
			p->flags |= (1 << (tmp + 5));
	}
	if (p->flags & ZERO && p->flags & MINUS)
		p->flags &= ~ZERO;
	if (p->flags & PLUS && p->flags & SPACE)
		p->flags &= ~SPACE;
	if (p->min_len < 0)
	{
		p->min_len *= -1;
		p->flags |= MINUS;
	}
}

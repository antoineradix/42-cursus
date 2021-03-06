/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:50:27 by anradix           #+#    #+#             */
/*   Updated: 2019/11/18 16:56:51 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_printf *p, bool b)
{
	if (b == 0)
	{
		p->i = 0;
		p->len = 0;
	}
	p->tmp = 0;
	p->neg = 0;
	p->flags = 0;
	p->precision = 0;
	p->min_len = 0;
	p->base = 10;
}

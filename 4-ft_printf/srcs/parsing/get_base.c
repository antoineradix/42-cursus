/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:50:48 by anradix           #+#    #+#             */
/*   Updated: 2019/11/19 16:02:18 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_base(t_printf *p)
{
	if (*p->frmt == 'b')
		p->base = 2;
	else if (*p->frmt == 'p')
		p->base = 16;
	else if (*p->frmt == 'o')
		p->base = 8;
	else if (*p->frmt == 'x' || *p->frmt == 'X')
		p->base = 16;
	else
		p->base = 10;
}

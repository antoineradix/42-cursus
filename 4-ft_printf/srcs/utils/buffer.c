/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:58:29 by anradix           #+#    #+#             */
/*   Updated: 2019/11/19 17:07:27 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	stock_error(t_printf *p)
{
	char *tmp;

	tmp = &*p->frmt;
	while (*tmp != '%')
		tmp--;
	while (tmp <= p->frmt)
		n_buffer(p, *tmp++, 1);
}

void	n_buffer(t_printf *p, char c, size_t n)
{
	if (n <= 0)
		return ;
	while (n--)
	{
		if (p->i == BUFF_SIZE)
		{
			write(1, p->buff, p->i);
			p->i = 0;
		}
		p->buff[p->i] = c;
		p->i++;
		p->len++;
	}
}

void	s_buffer(t_printf *p, char *s, size_t n)
{
	if (n == 0)
		return ;
	while (n--)
	{
		if (p->i == BUFF_SIZE)
		{
			write(1, p->buff, p->i);
			p->i = 0;
		}
		p->buff[p->i] = *s;
		p->i++;
		p->len++;
		s++;
	}
}

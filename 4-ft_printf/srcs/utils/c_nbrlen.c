/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_nbrlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:45:40 by anradix           #+#    #+#             */
/*   Updated: 2019/11/19 16:37:45 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_nbrlen(uintmax_t nb, int base, int len)
{
	if (nb == 0 && len == 0)
		return (1);
	if (nb < 0)
		return (c_nbrlen(nb * -1, base, len + 1));
	return (nb == 0) ? len : c_nbrlen(nb / base, base, len + 1);
}

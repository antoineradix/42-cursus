/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:31:29 by anradix           #+#    #+#             */
/*   Updated: 2019/11/19 15:33:11 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	is_digit(const char c)
{
	return (c >= '0' && c <= '9' ? 1 : 0);
}
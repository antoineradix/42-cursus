/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:09:12 by anradix           #+#    #+#             */
/*   Updated: 2019/11/19 17:10:09 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_struct
{
	char		*frmt;
	char		buff[BUFF_SIZE];
	va_list		va;
	bool		neg;
	bool		tmp;
	int			flags;
	int			i;
	int			len;
	int			precision;
	int			min_len;
	int			base;
}				t_printf;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:10:25 by anradix           #+#    #+#             */
/*   Updated: 2019/11/19 17:19:16 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE 42
# endif

# define SPACE	(1 << 0)
# define MINUS	(1 << 1)
# define PLUS	(1 << 2)
# define HASH	(1 << 3)
# define ZERO	(1 << 4)
# define L		(1 << 5)
# define H		(1 << 6)
# define HH		(1 << 7)

#endif

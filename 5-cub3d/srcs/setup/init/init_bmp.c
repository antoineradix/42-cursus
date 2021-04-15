/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 19:23:58 by anradix           #+#    #+#             */
/*   Updated: 2020/09/21 19:49:31 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bmp	init_bmp(t_struct *s)
{
	t_bmp bmp;

	bmp.im_size = s->win.res.x * s->win.res.y * 4;
	bmp.zero = 0;
	bmp.data_offset = 54;
	bmp.size_dib = 40;
	bmp.zero = 0;
	bmp.bpp = 32;
	return (bmp);
}

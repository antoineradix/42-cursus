/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:11:45 by anradix           #+#    #+#             */
/*   Updated: 2020/09/16 05:12:04 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_minimap(t_struct *s)
{
	int bigest_side;
	int scale;

	if ((s->win.res.x < 150 || s->win.res.y < 150) ||
		(s->map.map_row < 5 || s->map.map_col < 5))
	{
		s->minimap.activate = 0;
		return ;
	}
	else
		s->minimap.activate = 1;
	bigest_side = (s->win.res.x < s->win.res.y) ? s->win.res.x : s->win.res.y;
	if (s->map.map_row < 14 || s->map.map_col < 14)
		bigest_side /= 11;
	else
		bigest_side /= 4;
	scale = (s->map.map_row > s->map.map_col) ? bigest_side / s->map.map_row
	: bigest_side / s->map.map_col;
	s->minimap.scale = (scale == 0) ? 1 : scale;
}

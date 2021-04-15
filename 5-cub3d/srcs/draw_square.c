/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 21:41:12 by anradix           #+#    #+#             */
/*   Updated: 2020/09/16 21:41:32 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_struct *s, t_vec_d4d pos, int color)
{
	int	i;
	int	j;

	i = pos.y1;
	while (i < pos.y2)
	{
		j = pos.x1;
		while (j < pos.x2)
		{
			s->im.data[i * s->win.res.x + j] = color;
			j++;
		}
		i++;
	}
}

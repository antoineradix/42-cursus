/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:02:12 by anradix           #+#    #+#             */
/*   Updated: 2020/09/16 05:25:58 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		get_map_size(t_struct *s, char **map)
{
	int x;
	int y;
	int tmp;

	x = 0;
	y = 0;
	while (map[y])
	{
		tmp = s_len(map[y], 0, 0);
		if (tmp > x)
			x = tmp;
		y++;
	}
	s->map.map_row = y;
	s->map.map_col = x;
}

char			**get_map(t_struct *s, char **map)
{
	char **new_map;

	get_map_size(s, map);
	if (!(new_map = m_alloc2d(s->map.map_row, s->map.map_col, ' ')))
		exit_game(ERR_MEM_ALLOC, s, 1);
	s_copy2d(map, new_map);
	m_free2d(s->map.map);
	return (new_map);
}

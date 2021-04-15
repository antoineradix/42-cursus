/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 17:38:47 by anradix           #+#    #+#             */
/*   Updated: 2020/09/18 17:38:50 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_sprite(t_map *map, float x, float y)
{
	return (map->map[(int)y][(int)x] == '2') ? 1 : 0;
}

bool	is_wall(t_map *map, float x, float y)
{
	return (map->map[(int)y][(int)x] == '1' || map->map[(int)y][(int)x] == ' ')
	? 1 : 0;
}

float	dist_point(t_vec_f2d a, t_vec_f2d b)
{
	return (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
}

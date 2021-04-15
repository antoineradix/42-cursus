/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <anradix@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 01:55:07 by user42            #+#    #+#             */
/*   Updated: 2020/09/18 16:31:16 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		render_ray(t_struct *s, t_ray *rays)
{
	int			id;
	t_vec_d4d	pos;

	id = -1;
	while (++id < s->win.res.x)
	{
		pos.x1 = s->player.pos.x * s->minimap.scale + 12;
		pos.y1 = s->player.pos.y * s->minimap.scale + 12;
		pos.x2 = s->minimap.scale * rays[id].wall.x + 12;
		pos.y2 = s->minimap.scale * rays[id].wall.y + 12;
		draw_line(s, pos, YELLOW);
	}
}

static void		render_player(t_struct *s, t_player *player)
{
	t_vec_d4d	pos;

	pos.x1 = player->pos.x * s->minimap.scale + 12;
	pos.y1 = player->pos.y * s->minimap.scale + 12;
	pos.x2 = pos.x1 + s->minimap.scale;
	pos.y2 = pos.y1 + s->minimap.scale;
	draw_square(s, pos, GREEN);
}

static void		render_minimap(t_struct *s, t_map *map, bool b)
{
	int			j;
	int			i;
	t_vec_d4d	pos;

	j = -1;
	while (++j < map->map_row)
	{
		i = -1;
		while (++i < map->map_col)
		{
			pos.x1 = i * s->minimap.scale + 12;
			pos.y1 = j * s->minimap.scale + 12;
			pos.x2 = pos.x1 + s->minimap.scale;
			pos.y2 = pos.y1 + s->minimap.scale;
			if (map->map[j][i] == '0' && b == 0)
				draw_square(s, pos, GREY);
			else if (map->map[j][i] == '1' && b == 0)
				draw_square(s, pos, BLACK);
			else if (map->map[j][i] == '2' && b == 1)
				draw_square(s, pos, RED);
		}
	}
}

void			generate_minimap(t_struct *s, t_ray *ray)
{
	render_minimap(s, &s->map, 0);
	render_ray(s, ray);
	render_player(s, &s->player);
	if (s->num_sprite > 0)
		render_minimap(s, &s->map, 1);
}

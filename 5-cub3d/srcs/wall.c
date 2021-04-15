/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 07:45:04 by anradix           #+#    #+#             */
/*   Updated: 2020/10/01 15:38:29 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		render_wall(t_struct *s, int x, t_vec_d2d bot_top, t_ray *ray)
{
	t_vec_f2d	tex;
	int			y;
	int			wall_face;

	if (ray[x].is_vert)
	{
		tex.x = ray[x].wall.y - (int)ray[x].wall.y;
		tex.x *= TEXTURE_SIZE;
		wall_face = ray[x].face_lr;
	}
	else
	{
		tex.x = ray[x].wall.x - (int)ray[x].wall.x;
		tex.x *= TEXTURE_SIZE;
		wall_face = ray[x].face_ud;
	}
	y = bot_top.y - 1;
	while (++y < bot_top.x)
	{
		tex.y = (y + (ray[x].stip_height / 2) - (s->win.res.y / 2))
		* ((float)TEXTURE_SIZE / ray[x].stip_height);
		s->im.data[y * s->win.res.x + x] =
		s->tex[wall_face].tex[(int)tex.x][(int)tex.y];
	}
}

static void		render_background(t_struct *s)
{
	t_vec_d4d sky;
	t_vec_d4d floor;

	sky = (t_vec_d4d){0, 0, s->win.res.x, s->win.res.y / 2};
	floor = (t_vec_d4d){0, s->win.res.y / 2, s->win.res.x, s->win.res.y};
	draw_square(s, sky, s->win.color_sky);
	draw_square(s, floor, s->win.color_floor);
}

void			generate_wall(t_struct *s, t_player *player, t_ray *ray)
{
	int		i;
	int		top;
	int		bot;
	float	per_dist;

	i = -1;
	render_background(s);
	while (++i < s->win.res.x)
	{
		if (ray[i].dist == 0.00)
			ray[i].dist = 0.0001;
		per_dist = ray[i].dist * cos(ray[i].angle - player->rotate_angle);
		ray[i].stip_height = (1 / per_dist) * ((s->win.res.x / 2)
		/ (tan(s->player.fov / 2)));
		top = (s->win.res.y / 2) - (ray[i].stip_height / 2);
		top = (top < 0) ? 0 : top;
		bot = (s->win.res.y / 2) + (ray[i].stip_height / 2);
		bot = (bot > s->win.res.y) ? s->win.res.y : bot;
		render_wall(s, i, (t_vec_d2d){bot, top}, ray);
	}
}

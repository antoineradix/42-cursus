/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 04:57:13 by anradix           #+#    #+#             */
/*   Updated: 2020/09/18 17:37:54 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_horizontal(t_struct *s, t_player *player, t_map *map,
		t_ray *ray)
{
	t_vec_f2d	intercept;
	t_vec_f2d	step;

	intercept.y = floor(player->pos.y);
	intercept.y += (ray->face_ud == FAC_DOWN) ? 1 : 0;
	intercept.x = player->pos.x + (intercept.y - player->pos.y)
	/ tan(ray->angle);
	step.y = (ray->face_ud == FAC_UP) ? -1 : 1;
	step.x = 1 / tan(ray->angle);
	step.x *= (ray->face_lr == FAC_LEFT && step.x > 0) ? -1 : 1;
	step.x *= (ray->face_lr == FAC_RIGHT && step.x < 0) ? -1 : 1;
	ray->wall = intercept;
	while (ray->wall.x >= 0 && ray->wall.x < s->map.map_col
		&& ray->wall.y >= 0 && ray->wall.y < s->map.map_row)
	{
		if (is_wall(map, ray->wall.x, ray->wall.y +
		(ray->face_ud == FAC_UP ? -1 : 0)))
			break ;
		ray->wall.x += step.x;
		ray->wall.y += step.y;
	}
}

void	ray_vertical(t_struct *s, t_player *player, t_map *map, t_ray *ray)
{
	t_vec_f2d	intercept;
	t_vec_f2d	step;

	intercept.x = floor(player->pos.x);
	intercept.x += (ray->face_lr == FAC_RIGHT) ? 1 : 0;
	intercept.y = player->pos.y + (intercept.x - player->pos.x)
	* tan(ray->angle);
	step.x = ray->face_lr == FAC_LEFT ? -1 : 1;
	step.y = tan(ray->angle);
	step.y *= (ray->face_ud == FAC_UP && step.y > 0) ? -1 : 1;
	step.y *= (ray->face_ud == FAC_DOWN && step.y < 0) ? -1 : 1;
	ray->wall = intercept;
	while (ray->wall.x >= 0 && ray->wall.x < s->map.map_col &&
	ray->wall.y >= 0 && ray->wall.y < s->map.map_row)
	{
		if (is_wall(map, ray->wall.x + (ray->face_lr == FAC_LEFT ? -1 : 0),
		ray->wall.y))
			break ;
		ray->wall.x += step.x;
		ray->wall.y += step.y;
	}
}

void	cast_ray(t_struct *s, t_player *player, t_map *map, t_ray *ray)
{
	t_vec_f2d	hor;
	float		dist_hor;
	float		dist_ver;

	ray_horizontal(s, player, map, ray);
	hor = (t_vec_f2d){ray->wall.x, ray->wall.y};
	ray_vertical(s, player, map, ray);
	if ((dist_ver = dist_point(player->pos, ray->wall))
		> (dist_hor = dist_point(player->pos, hor)))
	{
		ray->wall = hor;
		ray->dist = dist_hor;
	}
	else
	{
		ray->is_vert = 1;
		ray->dist = dist_ver;
	}
}

void	caste_all_rays(t_struct *s, t_player *player, t_ray *rays)
{
	float	ray_angle;
	int		i;

	ray_angle = player->rotate_angle - (s->player.fov / 2);
	i = -1;
	while (++i < s->win.res.x)
	{
		rays[i] = init_ray(rays[i], ray_angle);
		cast_ray(s, player, &s->map, &rays[i]);
		ray_angle += s->player.fov / s->win.res.x;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 05:08:20 by anradix           #+#    #+#             */
/*   Updated: 2020/10/03 10:23:31 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	fov_scaled(t_struct *s)
{
	float	scale_fov;

	if (s->win.res.x > s->win.res.y)
		return (1.0);
	scale_fov = (float)s->win.res.x / (float)s->win.res.y;
	scale_fov = -0.014 * pow(scale_fov, 3) -
	0.056 * pow(scale_fov, 2) + 1.075 * scale_fov - 0.005;
	return (scale_fov);
}

static float	speed_scaled(t_struct *s)
{
	float	scale_speed;

	scale_speed = (float)s->win.res.x + (float)s->win.res.y;
	scale_speed = 0.0034 * pow(1.0016, scale_speed);
	return (scale_speed * 0.79);
}

static float	rotate_scaled(int x, int y)
{
	if (x <= 100 && y <= 100)
		return (0.0008);
	else if (x < 300 || y <= 10)
		return (0.002);
	else if (x + y < 900)
		return (0.004);
	else if ((x + y) < 1700)
		return (0.008);
	return (0.02);
}

void			setup(t_struct *s, char *f_path)
{
	init_struct(s);
	parsing(s, f_path);
	init_mlx(s);
	init_textures(s, &s->tex[0], 0);
	init_minimap(s);
	s->player.fov = fov_scaled(s);
	s->player.move_speed = speed_scaled(s);
	s->player.rotate_speed = rotate_scaled(s->win.res.x, s->win.res.y);
}

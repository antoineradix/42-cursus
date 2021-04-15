/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:02:59 by anradix           #+#    #+#             */
/*   Updated: 2020/09/18 16:30:38 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	norm_angle(float angle)
{
	angle = remainder(angle, M_PI * 2);
	return (angle < 0) ? angle += M_PI * 2 : angle;
}

t_ray			init_ray(t_ray ray, float ray_angle)
{
	ray.angle = norm_angle(ray_angle);
	ray.wall = (t_vec_f2d){0, 0};
	ray.dist = 0;
	ray.is_vert = 0;
	ray.face_ud = (ray.angle > 0 && ray.angle < M_PI) ? FAC_DOWN : FAC_UP;
	ray.face_lr = (ray.angle < 0.5 * M_PI || ray.angle > 1.5 * M_PI) ?
	FAC_RIGHT : FAC_LEFT;
	ray.stip_height = 0;
	return (ray);
}

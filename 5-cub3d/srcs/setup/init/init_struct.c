/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 05:20:14 by anradix           #+#    #+#             */
/*   Updated: 2020/10/01 14:41:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_struct *s)
{
	s->win.res = (t_vec_d2d){-1, -1};
	s->player.pos = (t_vec_f2d){-1, -1};
	s->win.color_sky = -1;
	s->win.color_floor = -1;
	s->num_sprite = 0;
	s->tex[TEX_NO].path = NULL;
	s->tex[TEX_SO].path = NULL;
	s->tex[TEX_EA].path = NULL;
	s->tex[TEX_WE].path = NULL;
	s->tex[TEX_S].path = NULL;
	s->player.rotate_angle = -1;
}

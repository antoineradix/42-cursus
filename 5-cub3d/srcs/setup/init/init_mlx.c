/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 19:41:22 by anradix           #+#    #+#             */
/*   Updated: 2020/10/01 15:12:14 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		check_resolution(t_struct *s)
{
	int x;
	int y;

	mlx_get_screen_size(s->mlx_ptr, &x, &y);
	if (s->win.res.x > x || s->win.res.y > y)
	{
		s->win.res.x = x;
		s->win.res.y = y;
	}
	else if (s->win.res.x < 50 || s->win.res.y < 50)
	{
		s->win.res.x = 50;
		s->win.res.y = 50;
	}
}

void			init_mlx(t_struct *s)
{
	if (!(s->mlx_ptr = mlx_init()))
		exit_game(ERR_MLX, s, 2);
	check_resolution(s);
	if (s->save == 1)
		return ;
	if (!(s->win.w_ptr = mlx_new_window(s->mlx_ptr, s->win.res.x,
			s->win.res.y, "cub3d")))
		exit_game(ERR_MLX, s, 3);
}

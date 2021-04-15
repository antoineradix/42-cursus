/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 04:51:24 by anradix           #+#    #+#             */
/*   Updated: 2020/10/05 18:20:30 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int key, t_struct *s)
{
	if (key == ESC)
		exit_game(0, s, 6);
	if (key == UP || key == DOWN)
	{
		if (s->player.left_right != 0)
		{
			s->player.tmp_left_right = s->player.left_right;
			s->player.left_right = 0;
		}
		s->player.walk_dir = (key == UP) ? 1 : -1;
	}
	if (key == L_AROW || key == R_AROW)
		s->player.turn_dir = (key == R_AROW) ? 1 : -1;
	if (key == LEFT || key == RIGHT)
	{
		if (s->player.walk_dir != 0)
		{
			s->player.tmp_walk_dir = s->player.walk_dir;
			s->player.walk_dir = 0;
		}
		s->player.left_right = (key == RIGHT) ? 1 : -1;
	}
	return (0);
}

int		key_release(int key, t_struct *s)
{
	if (key == UP || key == DOWN)
	{
		s->player.walk_dir = 0;
		s->player.tmp_walk_dir = 0;
		if (s->player.tmp_left_right != 0)
		{
			s->player.left_right = s->player.tmp_left_right;
			s->player.tmp_left_right = 0;
		}
	}
	if (key == L_AROW || key == R_AROW)
		s->player.turn_dir = 0;
	if (key == LEFT || key == RIGHT)
	{
		s->player.left_right = 0;
		s->player.tmp_left_right = 0;
		if (s->player.tmp_walk_dir != 0)
		{
			s->player.walk_dir = s->player.tmp_walk_dir;
			s->player.tmp_walk_dir = 0;
		}
	}
	return (0);
}

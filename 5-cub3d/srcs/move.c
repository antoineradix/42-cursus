/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 04:55:42 by anradix           #+#    #+#             */
/*   Updated: 2020/10/05 18:01:48 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_map *map, t_player *player)
{
	float		move_step;
	t_vec_f2d	new_player;

	if (player->left_right == 1)
		player->rotate_angle += M_PI / 2;
	else if (player->left_right == -1)
		player->rotate_angle -= M_PI / 2;
	if (player->left_right != 0)
		player->walk_dir = 1;
	player->rotate_angle += player->turn_dir * player->rotate_speed;
	move_step = player->walk_dir * player->move_speed;
	new_player.x = player->pos.x + cos(player->rotate_angle) * move_step;
	new_player.y = player->pos.y + sin(player->rotate_angle) * move_step;
	if (!is_wall(map, new_player.x, new_player.y) &&
		!is_sprite(map, new_player.x, new_player.y))
		player->pos = new_player;
	if (player->left_right == 1)
		player->rotate_angle -= M_PI / 2;
	else if (player->left_right == -1)
		player->rotate_angle += M_PI / 2;
	if (player->left_right != 0)
		player->walk_dir = 0;
}

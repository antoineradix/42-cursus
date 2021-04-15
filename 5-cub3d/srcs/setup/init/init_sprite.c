/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 08:50:50 by anradix           #+#    #+#             */
/*   Updated: 2020/09/16 06:04:38 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_sprite(t_struct *s, int x, int y)
{
	t_sprite	*sprite;

	s->num_sprite++;
	if (!(sprite = malloc(sizeof(*sprite))))
		return (0);
	sprite->pos.x = x + 0.5;
	sprite->pos.y = y + 0.5;
	sprite->texture = TEX_S;
	sprite->next = (s->sprite) ? s->sprite : NULL;
	s->sprite = sprite;
	return (1);
}

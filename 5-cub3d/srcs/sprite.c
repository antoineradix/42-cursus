/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:26:31 by anradix           #+#    #+#             */
/*   Updated: 2020/10/06 09:14:57 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		sort_sprite(t_sprite **headin)
{
	t_sprite	*ptr;
	t_sprite	*ptr_prev;
	t_sprite	*ptr_next;

	if (*headin)
	{
		ptr = *headin;
		ptr_prev = NULL;
		while (ptr->next)
		{
			ptr_next = ptr->next;
			if (ptr->dist < ptr_next->dist)
			{
				ptr->next = ptr_next->next;
				ptr_next->next = ptr;
				if (ptr_prev)
					ptr_prev->next = ptr_next;
				else
					*headin = ptr_next;
				ptr = *headin;
			}
			ptr_prev = ptr;
			ptr = ptr->next;
		}
	}
}

static void		render_sprite_2(t_struct *s, int spt_size, t_vec_d2d ofst,
				t_ray *ray)
{
	int color;
	int i;
	int j;

	i = -1;
	while (++i < spt_size)
	{
		if ((ofst.x + i >= 0 && ofst.x + i <= s->win.res.x) &&
			(ray[ofst.x + i].dist > s->sprite->dist))
		{
			j = -1;
			while (++j < spt_size)
			{
				if (ofst.y + j >= 0 && ofst.y + j < s->win.res.y)
				{
					color = s->tex[TEX_S].tex[i * TEXTURE_SIZE / spt_size]
					[j * TEXTURE_SIZE / spt_size];
					if (color != 0)
						s->im.data[(ofst.y + j) * s->win.res.x +
						(s->win.res.x + ofst.x + i)] = color;
				}
			}
		}
	}
}

static void		render_sprite(t_struct *s, t_sprite *sprite,
				t_player *player, t_ray *ray)
{
	int			spt_size;
	float		sprite_dir;
	t_vec_d2d	ofst;

	sprite_dir = atan2(sprite->pos.y - player->pos.y,
	sprite->pos.x - player->pos.x);
	while (sprite_dir - player->rotate_angle > M_PI)
		sprite_dir -= 2 * M_PI;
	while (sprite_dir - player->rotate_angle < -M_PI)
		sprite_dir += 2 * M_PI;
	if (s->win.res.y > s->win.res.x)
		spt_size = s->win.res.y / sprite->dist;
	else
		spt_size = s->win.res.x / sprite->dist;
	ofst.x = (sprite_dir - player->rotate_angle) *
	s->win.res.x / s->player.fov +
	(s->win.res.x / 2 - spt_size / 2);
	ofst.y = s->win.res.y / 2 - spt_size / 2;
	render_sprite_2(s, spt_size, ofst, ray);
}

void			generate_sprite(t_struct *s, t_player *player, t_ray *ray)
{
	t_sprite *head;

	head = s->sprite;
	while (head)
	{
		head->dist = dist_point(player->pos, head->pos);
		head = head->next;
	}
	sort_sprite(&s->sprite);
	head = s->sprite;
	while (s->sprite)
	{
		render_sprite(s, s->sprite, player, ray);
		s->sprite = s->sprite->next;
	}
	s->sprite = head;
}

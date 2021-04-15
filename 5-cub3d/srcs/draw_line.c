/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 04:50:16 by anradix           #+#    #+#             */
/*   Updated: 2020/10/01 15:24:28 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			draw_line2(t_struct *s, t_vec_d4d pos, unsigned int dx,
								int color)
{
	float			a;
	unsigned int	x;
	t_vec_d2d		end;

	if (pos.x1 > pos.x2)
	{
		m_swap(&pos.x1, &pos.x2);
		m_swap(&pos.y1, &pos.y2);
	}
	a = ((float)(pos.y2 - pos.y1) / (pos.x2 - pos.x1));
	x = 0;
	while (x < dx + 1)
	{
		end = (t_vec_d2d){(int)(x + pos.x1), (int)(pos.y1 + (x * a))};
		s->im.data[end.y * s->win.res.x + end.x] = color;
		x++;
	}
}

static void			draw_line3(t_struct *s, t_vec_d4d pos, t_vec_d2d d,
					int color)
{
	t_vec_d2d	end;
	float		a;
	int			y;

	if (pos.y1 > pos.y2)
	{
		m_swap(&pos.x1, &pos.x2);
		m_swap(&pos.y1, &pos.y2);
	}
	a = ((float)(pos.x2 - pos.x1) / (pos.y2 - pos.y1));
	y = 0;
	while (y < d.y + 1)
	{
		end = (t_vec_d2d){(int)(pos.x1 + (y * a)), (int)(y + pos.y1)};
		s->im.data[end.y * s->win.res.x + end.x] = color;
		y++;
	}
}

static void			draw_line4(t_struct *s, t_vec_d4d pos, int color)
{
	int			y;
	t_vec_d2d	end;

	if (pos.y1 > pos.y2)
		m_swap(&pos.y1, &pos.y2);
	y = pos.y1;
	while (y < pos.y2 + 1)
	{
		end.x = pos.x1;
		end.y = y;
		s->im.data[end.y * s->win.res.x + end.x] = color;
		y++;
	}
}

static void			draw_line5(t_struct *s, t_vec_d4d pos, int color)
{
	int			x;
	t_vec_d2d	end;

	if (pos.x1 > pos.x2)
	{
		m_swap(&pos.x1, &pos.x2);
		m_swap(&pos.y1, &pos.y2);
	}
	x = pos.x1;
	while (x < pos.x2 + 1)
	{
		end.x = x;
		end.y = pos.y1;
		s->im.data[end.y * s->win.res.x + end.x] = color;
		x++;
	}
}

void				draw_line(t_struct *s, t_vec_d4d pos, int color)
{
	t_vec_d2d	d;

	d = (t_vec_d2d) {abs(pos.x2 - pos.x1), abs(pos.y2 - pos.y1)};
	if (d.x >= d.y && d.x != 0 && d.y != 0)
		draw_line2(s, pos, d.x, color);
	if (d.x < d.y && d.x != 0 && d.y != 0)
		draw_line3(s, pos, d, color);
	if (d.x == 0)
		draw_line4(s, pos, color);
	if (d.y == 0)
		draw_line5(s, pos, color);
}

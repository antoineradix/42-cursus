/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 05:33:22 by anradix           #+#    #+#             */
/*   Updated: 2020/09/16 05:34:42 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool		all_id_found(t_struct *s)
{
	if (!s->tex[TEX_NO].path || !s->tex[TEX_SO].path || !s->tex[TEX_WE].path
		|| !s->tex[TEX_EA].path || !s->tex[TEX_S].path)
		return (0);
	return (s->win.color_sky <= -1 || s->win.color_floor <= -1 ||
	s->win.res.x <= -1) ? 0 : 1;
}

static bool		parsing_line_id(t_struct *s, char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (!*line)
		return (1);
	if (*line == 'R' && s->win.res.x == -1)
		return (get_resolution(&s->win.res.x, &s->win.res.y, line + 1));
	else if (*line == 'N' && *(line + 1) == 'O' && !s->tex[TEX_NO].path)
		return ((s->tex[TEX_NO].path = get_texture_path(line + 2)) ? 1 : 0);
	else if (*line == 'S' && *(line + 1) == 'O' && !s->tex[TEX_SO].path)
		return ((s->tex[TEX_SO].path = get_texture_path(line + 2)) ? 1 : 0);
	else if (*line == 'W' && *(line + 1) == 'E' && !s->tex[TEX_WE].path)
		return ((s->tex[TEX_WE].path = get_texture_path(line + 2)) ? 1 : 0);
	else if (*line == 'E' && *(line + 1) == 'A' && !s->tex[TEX_EA].path)
		return ((s->tex[TEX_EA].path = get_texture_path(line + 2)) ? 1 : 0);
	else if (*line == 'S' && !s->tex[TEX_S].path)
		return ((s->tex[TEX_S].path = get_texture_path(line + 1)) ? 1 : 0);
	else if (*line == 'F' && s->win.color_floor)
		return (get_rgb(&s->win.color_floor, line + 1));
	else if (*line == 'C' && s->win.color_sky)
		return (get_rgb(&s->win.color_sky, line + 1));
	return (0);
}

int				parsing_id(t_struct *s, char **map)
{
	int i;

	i = 0;
	while (*map && !all_id_found(s))
	{
		if (!parsing_line_id(s, *map))
			return (0);
		map++;
		i++;
	}
	return (all_id_found(s)) ? i : 0;
}

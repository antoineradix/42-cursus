/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 05:26:41 by anradix           #+#    #+#             */
/*   Updated: 2020/10/02 01:46:05 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool		is_closed(char **map, int i, int j)
{
	if (i == 0 || map[j][i - 1] == ' ' || map[j][i - 1] == '\t')
		return (0);
	if (map[j][i + 1] == ' ' || map[j][i + 1] == '\t' || map[j][i + 1] == '\0')
		return (0);
	if (j == 0 || map[j - 1][i] == ' ' || map[j - 1][i] == '\t')
		return (0);
	if (map[j + 1] == NULL || map[j + 1][i] == ' ' || map[j + 1][i] == '\t')
		return (0);
	return (1);
}

static void		set_pos(t_struct *s, char c, int x, int y)
{
	if (c == 'W')
		s->player.rotate_angle = 0;
	else if (c == 'N')
		s->player.rotate_angle = M_PI * 1.5;
	else if (c == 'E')
		s->player.rotate_angle = M_PI * 3;
	else if (c == 'S')
		s->player.rotate_angle = M_PI * 4.5;
	s->player.pos = (t_vec_f2d){(double)x + 0.5, (double)y + 0.5};
}

static bool		is_valid(t_struct *s, char **map, int j)
{
	int i;

	i = 0;
	while (map[j][i])
	{
		if (!s_find(map[j][i], " \t012NSEW"))
			return (0);
		if (s_find(map[j][i], "NSEW"))
		{
			if (s->player.pos.x != -1)
				return (0);
			set_pos(s, map[j][i], i, j);
			map[j][i] = '0';
		}
		if ((map[j][i] == '0' || map[j][i] == '2') && !is_closed(map, i, j))
			return (0);
		if (map[j][i] == '2' && !init_sprite(s, i, j))
			return (0);
		i++;
	}
	return (1);
}

static bool		map_is_valid(t_struct *s, char **map)
{
	int j;

	if (!map || !*map)
		return (0);
	j = 0;
	while (map[j])
	{
		if (!is_valid(s, map, j))
			return (0);
		j++;
	}
	return (1);
}

void			parsing_map(t_struct *s, char **map)
{
	s->map.map = get_map(s, map);
	if (!map_is_valid(s, s->map.map))
		exit_game(ERR_INVALID_MAP, s, 2);
	if (s->player.pos.x == -1)
		exit_game(ERR_STARTING_POS, s, 2);
}

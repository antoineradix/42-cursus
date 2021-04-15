/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 21:15:08 by anradix           #+#    #+#             */
/*   Updated: 2020/09/22 12:47:21 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool		check_empty_line(char *map)
{
	int i;

	i = s_len(map, 0, 0);
	while (i-- > 0)
		if (map[i] == '\n' && map[i - 1] == '\n')
			break ;
	while (i > 0 && map[i] == '\n')
		i--;
	while (i > 1 && map[i - 1] != '\n')
		i--;
	while (map[i] && (map[i] == ' ' || map[i] == '\t'))
		i++;
	if ((i > 0) && (map[i] == '0' || map[i] == '1' || map[i] == '2'))
		return (0);
	return (1);
}

static char		**stock_map(char *f_path)
{
	char	*tmp;
	char	**map;

	if (!(tmp = i_file(f_path)))
		exit_game(ERR_FILE_NOT_FOUND, NULL, 0);
	if (!check_empty_line(tmp))
	{
		free(tmp);
		exit_game(ERR_EMPTY_LINE, NULL, 0);
	}
	if (!(map = s_split(tmp, '\n')))
	{
		free(tmp);
		exit_game(ERR_MEM_ALLOC, NULL, 0);
	}
	free(tmp);
	return (map);
}

static void		check_file_name(char *f_path)
{
	int len;

	len = s_len(f_path, 0, 0) - 4;
	if (len < 1 || s_diff(f_path + len, ".cub"))
		exit_game(ERR_FILE_NAME, NULL, 0);
}

void			parsing(t_struct *s, char *f_path)
{
	int i;

	check_file_name(f_path);
	s->map.map = stock_map(f_path);
	if (!(i = parsing_id(s, s->map.map)))
		exit_game(ERR_INVALID_ID, s, 1);
	parsing_map(s, &s->map.map[i]);
}

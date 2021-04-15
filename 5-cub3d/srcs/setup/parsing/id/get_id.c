/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 05:33:01 by anradix           #+#    #+#             */
/*   Updated: 2020/09/16 05:33:11 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	get_resolution(int *res_x, int *res_y, char *line)
{
	int nb_id;

	nb_id = 0;
	while (nb_id <= 2)
	{
		while (*line && (*line == ' ' || *line == '\t'))
			line++;
		if (*line == '\0' || !(*line >= '0' && *line <= '9'))
			break ;
		if (nb_id == 0)
			*res_x = c_atoi(line);
		else if (nb_id == 1)
			*res_y = c_atoi(line);
		while (*line && *line >= '0' && *line <= '9')
			line++;
		nb_id++;
	}
	return (nb_id == 2) ? 1 : 0;
}

char	*get_texture_path(char *line)
{
	char *tmp;

	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (*line == '\0' || !(tmp = m_dup(&*line)))
		return (NULL);
	while (*line && *line != ' ')
		line++;
	while (*line && *line == ' ')
		line++;
	if (!*line)
		return (tmp);
	free(tmp);
	return (NULL);
}

bool	get_rgb(int *id_rgb, char *line)
{
	int nb_id;
	int	tmp;

	nb_id = 0;
	*id_rgb = 0;
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	while (nb_id <= 3)
	{
		if (!(*line >= '0' && *line <= '9'))
			return (0);
		if ((tmp = c_atoi(line)) < 0 || tmp > 255)
			return (0);
		*id_rgb <<= (nb_id == 0) ? 0 : 8;
		*id_rgb += tmp;
		while (*line != '\0' && *line >= '0' && *line <= '9')
			line++;
		if (nb_id++ == 3 || *line != ',')
			break ;
		line++;
	}
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	return (*line == '\0' && nb_id == 3) ? 1 : 0;
}

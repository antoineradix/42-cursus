/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 05:03:13 by anradix           #+#    #+#             */
/*   Updated: 2020/09/16 20:43:55 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	free_tex(t_struct *s, int err_value)
{
	int i;

	i = 0;
	while (i < NB_TEXTURE)
	{
		if (err_value >= 6)
			mlx_destroy_image(s->mlx_ptr, s->tex[i].ptr);
		free(s->tex[i].path);
		i++;
	}
}

static	void	free_sprite(t_struct *s)
{
	t_sprite	*ptr;

	while (s->sprite)
	{
		ptr = s->sprite->next;
		free(s->sprite);
		s->sprite = ptr;
	}
	free(s->sprite);
	s->sprite = NULL;
}

static	void	free_mlx(t_struct *s, int err_value)
{
	if (err_value >= 4 && s->save == 0)
		mlx_destroy_window(s->mlx_ptr, s->win.w_ptr);
	if (err_value >= 5)
		mlx_destroy_image(s->mlx_ptr, s->im.img_ptr);
}

void			exit_game(const char *err_info, t_struct *s, int err_value)
{
	if (err_info != NULL)
	{
		p_str("Error\n");
		p_str((char*)err_info);
		p_str("\n\nusage: ./cub3d [map.cub] or ./cub3d [map.cub] [--save]\n");
	}
	if (err_value >= 1)
	{
		free_tex(s, err_value);
		m_free2d(s->map.map);
	}
	if (err_value >= 2)
		free_sprite(s);
	if (err_value >= 3)
		free_mlx(s, err_value);
	exit(EXIT_SUCCESS);
}

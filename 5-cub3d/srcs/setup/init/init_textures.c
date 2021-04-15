/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:01:44 by anradix           #+#    #+#             */
/*   Updated: 2020/10/07 09:51:06 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		free_before_exit(t_struct *s, int i)
{
	while (i >= 0)
		mlx_destroy_image(s->mlx_ptr, s->tex[i--].ptr);
	exit_game(ERR_INIT_TEXTURES, s, 2);
}

void			init_textures(t_struct *s, t_tex *tex, int i)
{
	int y;
	int x;

	if (!(tex->ptr = mlx_xpm_file_to_image(s->mlx_ptr, tex->path,
										&tex->width, &tex->height)))
		free_before_exit(s, i - 1);
	if (!(tex->data = (int *)mlx_get_data_addr(tex->ptr, &tex->bpp,
											&tex->size_l, &tex->endian)))
		free_before_exit(s, i);
	y = -1;
	if (tex->height <= 0 || tex->height != TEXTURE_SIZE ||
		tex->width != TEXTURE_SIZE)
		free_before_exit(s, i);
	while (++y < tex->height)
	{
		x = -1;
		while (++x < tex->width)
			tex->tex[y][x] = (int)tex->data[x * tex->width + y];
	}
	i++;
	if (i < NB_TEXTURE)
		init_textures(s, &s->tex[i], i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:05:56 by anradix           #+#    #+#             */
/*   Updated: 2020/10/01 15:18:42 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** How to create bmp::
** http://www.machaon.fr/isn/representation/Les%20fichiers%20images%20BMP.html
*/

static void		write_header(t_struct *s, int fd, t_bmp bmp)
{
	write(fd, &"BM", 2);
	write(fd, &bmp.im_size, 4);
	write(fd, &bmp.zero, 4);
	write(fd, &bmp.data_offset, 4);
	write(fd, &bmp.size_dib, 4);
	write(fd, &s->win.res.x, 4);
	write(fd, &s->win.res.y, 4);
	write(fd, &bmp.planes, 2);
	write(fd, &bmp.bpp, 2);
	write(fd, &bmp.zero, 8);
	write(fd, &bmp.zero, 8);
	write(fd, &bmp.zero, 8);
}

static void		write_img(t_struct *s, int fd)
{
	int y;
	int x;

	y = s->win.res.y;
	while (y-- >= 0)
	{
		x = 0;
		while (x < s->win.res.x)
			write(fd, &(s->im.data[(y * s->win.res.x) + x++]), 4);
	}
}

void			save(t_struct *s)
{
	int		fd;
	t_bmp	bmp;

	update(s);
	if ((fd = open("screenshot.bmp",
		O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IWOTH)) < 0)
		exit_game(0, s, 6);
	bmp = init_bmp(s);
	write_header(s, fd, bmp);
	write_img(s, fd);
	close(fd);
	exit_game(0, s, 6);
}

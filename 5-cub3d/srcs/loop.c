/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:56:53 by user42            #+#    #+#             */
/*   Updated: 2020/10/05 17:36:13 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	forced_exit(t_struct *s)
{
	exit_game(0, s, 6);
	return (0);
}

static void	refresh_mlx(t_struct *s)
{
	if (s->im.img_ptr != NULL)
		mlx_destroy_image(s->mlx_ptr, s->im.img_ptr);
	if (!(s->im.img_ptr = mlx_new_image(s->mlx_ptr,
			s->win.res.x, s->win.res.y)))
		exit_game(ERR_MLX, s, 6);
	if (!(s->im.data = (int *)mlx_get_data_addr(s->im.img_ptr,
			&s->im.bpp, &s->im.size_l,
		&s->im.endian)))
		exit_game(ERR_MLX, s, 6);
}

int			update(t_struct *s)
{
	t_ray ray[s->win.res.x];

	refresh_mlx(s);
	move(&s->map, &s->player);
	caste_all_rays(s, &s->player, ray);
	generate_wall(s, &s->player, ray);
	generate_sprite(s, &s->player, ray);
	if (s->minimap.activate)
		generate_minimap(s, ray);
	if (!s->save)
		mlx_put_image_to_window(s->mlx_ptr, s->win.w_ptr, s->im.img_ptr, 0, 0);
	return (0);
}

void		game_loop(t_struct *s)
{
	mlx_hook(s->win.w_ptr, 2, 1, key_press, s);
	mlx_hook(s->win.w_ptr, 3, 2, key_release, s);
	mlx_hook(s->win.w_ptr, 17, (1 << 17), forced_exit, s);
	mlx_loop_hook(s->mlx_ptr, update, s);
	mlx_loop(s->mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 04:35:48 by anradix           #+#    #+#             */
/*   Updated: 2020/10/06 10:26:44 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <../minilibx-linux/mlx.h>
# include <stdbool.h>
# include "mylib.h"
# include "const.h"
# include "struct.h"
# include "key_us.h"

int			main(int ac, char **av);
void		setup(t_struct *s, char *f_path);
void		init_struct(t_struct *s);
void		parsing(t_struct *s, char *f_path);
int			parsing_id(t_struct *s, char **map);
bool		get_resolution(int *res_x, int *res_y, char *line);
char		*get_texture_path(char *line);
bool		get_rgb(int *id_rgb, char *line);
void		parsing_map(t_struct *s, char **map);
char		**get_map(t_struct *s, char **map);
t_bmp		init_bmp(t_struct *s);
void		init_mlx(t_struct *s);
void		init_textures(t_struct *s, t_tex *tex, int i);
void		init_struct(t_struct *s);
bool		init_sprite(t_struct *s, int x, int y);
t_ray		init_ray(t_ray ray, float ray_angle);
void		init_minimap(t_struct *s);
void		save(t_struct *s);
void		game_loop(t_struct *s);
int			key_press(int key, t_struct *s);
int			key_release(int key, t_struct *s);
void		move(t_map *map, t_player *player);
void		caste_all_rays(t_struct *s, t_player *player, t_ray *rays);
bool		is_sprite(t_map *map, float x, float y);
bool		is_wall(t_map *map, float x, float y);
float		dist_point(t_vec_f2d a, t_vec_f2d b);
void		generate_wall(t_struct *s, t_player *player, t_ray *ray);
void		generate_sprite(t_struct *s, t_player *player, t_ray *ray);
void		generate_minimap(t_struct *s, t_ray *ray);
void		draw_line(t_struct *s, t_vec_d4d pos, int color);
void		draw_square(t_struct *s, t_vec_d4d pos, int color);
int			update(t_struct *s);
void		exit_game(const char *err_info, t_struct *s, int err_value);

#endif

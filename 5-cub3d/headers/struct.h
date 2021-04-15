/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 19:52:22 by anradix           #+#    #+#             */
/*   Updated: 2020/10/05 17:56:40 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_vec_d2d
{
	int				x;
	int				y;
}					t_vec_d2d;

typedef struct		s_vec_d4d
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_vec_d4d;

typedef struct		s_vec_f2d
{
	float			x;
	float			y;
}					t_vec_f2d;

typedef struct		s_minimap
{
	int				scale;
	bool			activate;
}					t_minimap;

typedef struct		s_im
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_im;

typedef struct		s_tex
{
	int				tex[TEXTURE_SIZE][TEXTURE_SIZE];
	char			*path;
	void			*ptr;
	int				*data;
	int				width;
	int				height;
	int				bpp;
	int				size_l;
	int				endian;
}					t_tex;

typedef struct		s_ray
{
	float			angle;
	t_vec_f2d		wall;
	float			dist;
	int				is_vert;
	int				face_ud;
	int				face_lr;
	int				stip_height;
	int				wall_content;
}					t_ray;

typedef struct		s_map
{
	char			**map;
	int				map_row;
	int				map_col;
}					t_map;

typedef struct		s_player
{
	t_vec_f2d		pos;
	int				turn_dir;
	int				walk_dir;
	int				tmp_walk_dir;
	int				left_right;
	int				tmp_left_right;
	float			rotate_angle;
	float			move_speed;
	float			rotate_speed;
	float			fov;
}					t_player;

typedef struct		s_sprite
{
	t_vec_f2d		pos;
	float			dist;
	int				texture;
	struct s_sprite	*next;
}					t_sprite;

typedef struct		s_window
{
	t_vec_d2d		res;
	void			*w_ptr;
	int				color_sky;
	int				color_floor;
}					t_window;

typedef struct		s_struct
{
	void			*mlx_ptr;
	bool			save;
	int				num_sprite;
	t_window		win;
	t_minimap		minimap;
	t_map			map;
	t_player		player;
	t_im			im;
	t_sprite		*sprite;
	t_tex			tex[NB_TEXTURE];
}					t_struct;

typedef struct		s_bmp
{
	int				im_size;
	int				zero;
	int				data_offset;
	int				size_dib;
	short int		planes;
	short int		bpp;
}					t_bmp;

#endif

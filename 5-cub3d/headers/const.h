/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:07:39 by anradix           #+#    #+#             */
/*   Updated: 2020/09/22 14:14:08 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# define ERR_WRONG_ARG "Invalid arguments after ./cub3d"
# define ERR_FILE_NAME "Any file ending by .cub has been found"
# define ERR_FILE_NOT_FOUND "File not foud"
# define ERR_MEM_ALLOC "Memory allocation failed unexpectedly"
# define ERR_EMPTY_LINE "Empty line has been found in the map"
# define ERR_INVALID_ID "Wrong or missing ID"
# define ERR_INVALID_MAP "The description of the maps is invalid"
# define ERR_STARTING_POS "You have to set the starting postion of the player"
# define ERR_MLX "MLX unexpected behavior"
# define ERR_INIT_TEXTURES "Impossible to load textures"
# define ERR_SAVE "  "

# define RED 16711680
# define BLACK 0
# define GREEN 65280
# define YELLOW 16776960
# define GREY 6579300

# define TEXTURE_SIZE 64
# define NB_TEXTURE 5
# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3
# define TEX_S 4

# define FAC_UP 0
# define FAC_DOWN 1
# define FAC_LEFT 2
# define FAC_RIGHT 3

#endif

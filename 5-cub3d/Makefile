# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anradix <anradix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/19 14:09:29 by anradix           #+#    #+#              #
#    Updated: 2020/10/06 10:26:20 by anradix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	Cub3D

CC				=	gcc

FLAGS			=	-Wall -Wextra -Werror

SRCS			=	srcs/main.c\
					srcs/exit.c\
					srcs/setup/setup.c\
					srcs/setup/init/init_bmp.c\
					srcs/setup/init/init_struct.c\
					srcs/setup/init/init_mlx.c\
					srcs/setup/init/init_textures.c\
					srcs/setup/init/init_ray.c\
					srcs/setup/init/init_sprite.c\
					srcs/setup/init/init_minimap.c\
					srcs/setup/parsing/parsing.c\
					srcs/setup/parsing/id/parsing_id.c\
					srcs/setup/parsing/id/get_id.c\
					srcs/setup/parsing/map/parsing_map.c\
					srcs/setup/parsing/map/get_map.c\
					srcs/minimap.c\
					srcs/draw_square.c\
					srcs/draw_line.c\
					srcs/move.c\
					srcs/loop.c\
					srcs/key.c\
					srcs/utils.c\
					srcs/ray.c\
					srcs/wall.c\
					srcs/sprite.c\
					srcs/save.c\

OBJS			=	$(SRCS:.c=.o)

HEADERS			=	./headers 

MYLIB_HEADER	=	./mylib

MYLIB			=	./mylib/mylib.a

MLX_FLAGS		=	-lbsd -lXext -lX11

all: $(NAME) $(MYLIB)

$(NAME): $(MYLIB) $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MYLIB) ./minilibx-linux/libmlx.a $(MLX_FLAGS) -lm


$(MYLIB):
	@$(MAKE) all -C ./mylib

%.o: %.c
	@$(CC) $(FLAGS) -I $(HEADERS) -I $(MYLIB_HEADER) -o $@ -c $< -lm

clean:
	@make clean -C ./mylib
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -C ./mylib
	@rm -f $(NAME)

re: fclean all
	@rm -f $(OBJS)

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:59:37 by anradix           #+#    #+#             */
/*   Updated: 2020/09/16 06:03:46 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
	t_struct s;

	if ((ac < 2 || ac > 3) || (ac == 3 && s_diff(av[2], "--save")))
		exit_game(ERR_WRONG_ARG, NULL, 0);
	s.save = (ac == 3) ? 1 : 0;
	setup(&s, av[1]);
	(s.save == 1) ? save(&s) : game_loop(&s);
	return (1);
}

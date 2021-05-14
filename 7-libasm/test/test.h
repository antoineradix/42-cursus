/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:41:14 by anradix           #+#    #+#             */
/*   Updated: 2021/05/11 15:02:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../libasm.h"

bool	test_write(int nb_test);
bool	test_read(int nb_test);
bool	test_strlen(int nb_test);
bool	test_strcpy(int nb_test);
bool	test_strcmp(int nb_test);
bool	test_strdup(int nb_test);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:06:10 by anradix           #+#    #+#             */
/*   Updated: 2019/11/14 16:42:13 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*save_line(char *f)
{
	size_t i;
	size_t j;

	i = slen(f, 0, '\n') + 1;
	j = 0;
	while (f[i])
		f[j++] = f[i++];
	f[j] = '\0';
	return (f);
}

int			get_next_line(int fd, char **line)
{
	static char	*f[1];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, buff, 0) != 0
		|| (!(f[fd]) && !(f[fd] = snew(0))))
		return (-1);
	while (!schr(f[fd], '\n') && (ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = f[fd];
		if (!(f[fd] = sjoin(tmp, buff)))
			return (-1);
		free(tmp);
	}
	if (!(*line = ssub(f[fd], 0, slen(f[fd], 0, '\n'))))
		return (-1);
	if (!schr(f[fd], '\n'))
	{
		free(f[fd]);
		return (0);
	}
	save_line(f[fd]);
	return (1);
}

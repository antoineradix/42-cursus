/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:51:23 by anradix           #+#    #+#             */
/*   Updated: 2019/11/14 16:41:56 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*snew(size_t size)
{
	char *s;

	if (!(s = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	size++;
	while (size--)
		s[size] = '\0';
	return (s);
}

int		schr(char *s, char c)
{
	if (*s == '\0')
		return (0);
	return (*s == c) ? 1 : schr(s + 1, c);
}

size_t	slen(char *s, size_t len, char c)
{
	return (!s || !*s || *s == c) ? len : slen(s + 1, len + 1, c);
}

char	*sjoin(char *s1, char *s2)
{
	char	*join;
	size_t	l1;
	size_t	l2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	l1 = slen(s1, 0, '\0');
	l2 = slen(s2, 0, '\0');
	if (!(join = snew(l1 + l2)))
		return (NULL);
	i = 0;
	while (s1 && i < l1)
	{
		join[i] = s1[i];
		i++;
	}
	while (s2 && i - l1 < l2)
	{
		join[i] = s2[i - l1];
		i++;
	}
	join[i] = '\0';
	return (join);
}

char	*ssub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s)
	{
		if (!(str = snew(len)))
			return (NULL);
		while (i < len)
			str[i++] = s[start++];
		return (str);
	}
	return (NULL);
}

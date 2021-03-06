/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:42:37 by anradix           #+#    #+#             */
/*   Updated: 2018/11/21 13:44:18 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	k;

	i = 0;
	j = 0;
	while (str[i + 1] != '\0')
		i++;
	while (j < i)
	{
		k = str[j];
		str[j] = str[i];
		str[i] = k;
		j++;
		i--;
	}
	return (str);
}

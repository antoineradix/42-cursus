/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:53:02 by anradix           #+#    #+#             */
/*   Updated: 2018/11/21 13:53:15 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_add_list(t_list *list, char *str)
{
	t_list	*new;
	t_list	*begin;

	begin = list;
	if ((new = ft_create_list(str)) == NULL)
		return (NULL);
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
		begin = new;
	return (begin);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:50:21 by mperseus          #+#    #+#             */
/*   Updated: 2019/09/21 15:01:56 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*res;
	t_list	*begin;

	res = NULL;
	begin = NULL;
	if (lst && f)
	{
		if (!(res = f(lst)))
			return (NULL);
		begin = res;
		while (lst->next)
		{
			if (!(res->next = f(lst->next)))
			{
				ft_lstdelmy(begin);
				return (NULL);
			}
			lst = lst->next;
			res = res->next;
		}
	}
	return (begin);
}

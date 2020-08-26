/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:49:47 by mperseus          #+#    #+#             */
/*   Updated: 2019/09/21 15:02:51 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*tmp;
	t_list	*nxt;

	if (alst && *alst && del)
	{
		tmp = *alst;
		while (tmp)
		{
			nxt = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = nxt;
		}
		*alst = NULL;
	}
}

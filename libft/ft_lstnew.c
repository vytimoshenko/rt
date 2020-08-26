/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:49:19 by mperseus          #+#    #+#             */
/*   Updated: 2019/09/21 11:17:01 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_node;
	void	*node_content;

	if (!(new_node = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new_node->content = NULL;
		new_node->content_size = 0;
	}
	else
	{
		if (!(node_content = ft_memalloc(content_size)))
		{
			free(new_node);
			return (NULL);
		}
		ft_memcpy(node_content, content, content_size);
		new_node->content = node_content;
		new_node->content_size = content_size;
	}
	new_node->next = NULL;
	return (new_node);
}

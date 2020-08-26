/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:56:17 by mperseus          #+#    #+#             */
/*   Updated: 2019/09/19 22:34:49 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void *tmp;

	tmp = b;
	while (len > 0)
	{
		*(unsigned char *)tmp = (unsigned char)c;
		tmp++;
		len--;
	}
	return (b);
}

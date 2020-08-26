/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:07:12 by mperseus          #+#    #+#             */
/*   Updated: 2019/09/21 16:00:56 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *tmp;

	if (!(dst) && !(src))
		return (NULL);
	tmp = dst;
	while (n > 0)
	{
		*(unsigned char *)tmp = *(const unsigned char *)src;
		tmp++;
		src++;
		n--;
	}
	return (dst);
}

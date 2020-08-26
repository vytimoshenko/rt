/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:03:25 by mperseus          #+#    #+#             */
/*   Updated: 2019/09/21 15:45:30 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*tmp;

	tmp = dst;
	while (n > 0)
	{
		*(unsigned char *)tmp = *(unsigned char *)src;
		if (*(unsigned char *)tmp == (unsigned char)c)
			return (++tmp);
		tmp++;
		src++;
		n--;
	}
	return (NULL);
}

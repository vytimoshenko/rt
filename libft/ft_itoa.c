/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:23:20 by mperseus          #+#    #+#             */
/*   Updated: 2019/12/24 01:41:34 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	long	nl;

	nl = n;
	len = ft_intlen(n);
	if (nl <= 0)
	{
		nl = -nl;
		len++;
	}
	s = malloc(sizeof(char) * (len + 1));
	if (!(s))
		return (NULL);
	s[len] = '\0';
	while (len > 0)
	{
		s[len - 1] = nl % 10 + '0';
		nl = nl / 10;
		len--;
	}
	if (n != 0 && *s == '0')
		*s = '-';
	return (s);
}

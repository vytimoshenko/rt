/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:18:21 by mperseus          #+#    #+#             */
/*   Updated: 2019/09/21 18:39:55 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *needle_found;
	char *needle_lost;

	if (!(*needle))
		return ((char *)haystack);
	while (*haystack)
	{
		if (*needle != *haystack)
		{
			haystack++;
			continue;
		}
		needle_found = (char *)haystack;
		needle_lost = (char *)needle;
		while (*needle_lost)
		{
			if (*haystack++ != *needle_lost++)
				break ;
			if (!(*needle_lost))
				return (needle_found);
		}
		haystack = needle_found;
		haystack++;
	}
	return (NULL);
}

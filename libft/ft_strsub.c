/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:02:20 by mperseus          #+#    #+#             */
/*   Updated: 2019/12/24 18:32:47 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res_str;

	if (s == NULL)
		return (0);
	i = 0;
	res_str = malloc(sizeof(char) * (len + 1));
	if (res_str == 0)
		return (0);
	while (len > 0)
	{
		res_str[i] = s[start];
		i++;
		start++;
		len--;
	}
	res_str[i] = '\0';
	return (res_str);
}
